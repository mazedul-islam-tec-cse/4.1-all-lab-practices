/* Compile with
* 	mpicc odd_even_sort.c -o ../bin/odd_even_sort
* Run with
*  mpirun -np 2 ../bin/odd_even_sort
* or with the fantastic bash shell script
*  ./mpi.sh odd_even_sort 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mpi.h"
#include<iostream>
using namespace std;

#define N 10000
#define MAX_ITEM 3*N
#define ROOT_RANK 0
#define MAX_OUTPUT 20

// Comparison function used by qsort
int compare_ints(const void* arg1, const void* arg2)
{
	int a1 = *(int *)arg1;
	int a2 = *(int *)arg2;
	if (a1 < a2) return -1;
	else if (a1 == a2) return 0;
	else return 1;
}

// Wrapper for qsort for integers. This sorts the array
// in place.
void qsort_ints(int *array, int array_len)
{
	qsort(array, (size_t)array_len, sizeof(int), compare_ints);
}

// Print out the contents of an array if the array
// is short enough
void print_array(int *array, int array_len)
{
	int i;
	for (i = 0; i < array_len && i < MAX_OUTPUT; i++)
	{
		printf("%d ", array[i]);
		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n");
}

// Sort the array in place using the odd-even interchange sort.
void sequential_odd_even_sort(int *a, int n)
{
	int done = 0, i, temp;
	while (!done)
	{
		done = 1;
		for (int phase = 0; phase < n; phase++)
		{
			if (phase % 2 == 0)
			{

				for (i = 1; i < n; i += 2)
				{
					if (a[i - 1] > a[i])
					{
						temp = a[i];
						a[i] = a[i - 1];
						a[i - 1] = temp;
						done = 0;
					}

				}
			}
			else
			{
				for (i = 1; i < n - 1; i += 2)
				{
					if (a[i] > a[i + 1])
					{
						temp = a[i];
						a[i] = a[i + 1];
						a[i + 1] = temp;
						done = 0;
					}
				}
			}
			 
				
		}
	} // end while !done
} // end sequential_odd_even_sort

  // Print a message indicating whether or not the arrays
  // are identical.
void compare_arrays(int *a1, int *a2, int len)
{
	int i;

	if (a1 == NULL || a2 == NULL)
	{
		printf("One of the arrays is null\n");
		return;
	}

	for (i = 0; i < len; i++)
		if (a1[i] != a2[i])
		{
			printf("The arrays don't match!\n");
			return;
		}
	printf("The comparison test succeeded\n");
} // end compare_arrays

  // Allocate space on the heap for an integer array of length len.
  // Fill it with integers pseudo-randomly chosen from the range
  // 0 to MAX_ITEM-1;
int *create_random_int_array(int len)
{
	int i;
	int *ret;
	ret = (int *)malloc(sizeof(int)*len);
	srand(1); // Seed the random number generator with a 1 so that the same
			  // array will be created every time the program is called.
			  // To get a different set of values for each run, seed it with
			  // the clock instead, i.e. srand(time(NULL));
	for (i = 0; i<len; i++)
		ret[i] = rand() % MAX_ITEM;
	return ret;
} // create_random_int_array

int main(int argc, char **argv)
{
	// Variables Stephanie used to write her parallel version.
	// You may or may not need all of them.
	const int TAG = 1; // the tag used for MPI_Send and MPI_Recv
	MPI_Status status;  // the status used for MPI_Recv
	int  numprocs, rank; // the number of processes, rank of this process
	int rc; // error code
	int i, tmp; // loop control and swap variables
	int array[] = { 10,12,1,2,5,3,4,8,35,6,0 ,7}; // pointer to full original array (that only root uses)
	int *my_array = NULL; // pointer to my section of the array
	int sorted_array[] = {0,1,2,3,4,5,6,7,8,10,12,35}; // pointer to sorted array (that only root uses)
	int length; // length of the full array
	int length_per_process; // length of each processes part of the array
	int local_count = 0; // variable used to indicated whether or not this processes'
						 // array segment is sorted
	int global_count; // variable to keep track of the number or processes whose
					  // array segments are sorted
	int left, right; // variables to store the boundary values sent to use from
					 // our left (rank-1) and right (rank+1) neighbors

					 /******* Initialize *******/
	rc = MPI_Init(&argc, &argv);
	if (rc != MPI_SUCCESS) {
		printf("Error starting MPI program. Terminating.\n");
		MPI_Abort(MPI_COMM_WORLD, rc);
	}

	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	// LET'S MAKE THE PROBLEM SIZE SUIT US RATHER THAN
	// WRITE LOTS OF CODE TO MAKE SURE WE CAN HANDLE ODD_SIZED DATA.
	// THIS IS A MASSIVE HACK!!!!
	// Call me Lizzy Borden.
	length_per_process =12 / numprocs;
	// if the number of items per proc is not even, then reduce it 
	// so it is even
	//if (length_per_process % 2 != 0)
		//length_per_process--;
	// If the number of items is not evenly divisible by the processors,
	// the reduce it so that it is.
	length = length_per_process*numprocs;

	// Assume only the root has access to the input. It needs to send it to the rest
	// of the processors. In this case, we mimic input by randomly creating an array.
	//if (rank == 1)
	//array = create_random_int_array(length);

	// Scatter the data by sending parts of it from the
	// root process to each of the other processes. The root
	// process does send data to itself, so my_array must be
	// a valid address on the root proccess. On non-root processes,
	// the first three arguments are ignored.
	// YOUR CODE GOES HERE!

	// While not all processes have sorted sections, do the odd even sort.
	// This means we sort our section, send our boundary values to our 
	// neighbors (procs rank-1 and rank+1), and receive boundary values
	// from our neighbors. If necessary our boundary values were out of 
	// order with respect to our neighbor's boundary values, then use
	// set our boundary values to be those or our neighbor's.
	// For each loop through the algorithm, determine whether or not this
	// process has a sorted segment of the array. Then, use MPI_Reduceall
	// to count the number of processes that have finished. If all have
	// finished, then stop looping. Otherwise, continue.
	// YOUR CODE GOES HERE!

	// Gather the array segments onto the root (in the variable
	// sorted_array)
	// YOUR CODE GOES HERE!

	// Test the result to make sure it is correct.
	if (rank == ROOT_RANK)
	{
		// Use a local odd-even sequential sort as a reference
		// If you would prefer to use qsort, then replace
		// the call to sequential_odd_even_sort with qsort_ints(array,length);
		sequential_odd_even_sort(array, length);
		// Compare the array sorted sequentially (array) with the
		// array sorted in parallel (sorted_array). They should be
		// the same.
		compare_arrays(array, sorted_array, length);
		for (int i = 0; i < length; i++)
		{
			cout << array[i] << " ";

		}
	}

	/******* Finalize *******/
	MPI_Finalize();
	// free my_array, sorted_array, and array as necessary
	// YOUR CODE GOES HERE!

	return 0;
}



