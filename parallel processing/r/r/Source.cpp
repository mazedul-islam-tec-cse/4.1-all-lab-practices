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
} 

void Get_data2(int a_ptr[], int l, int my_rank) {
	
		printf("Enter a, b, and n\n");
		for(int i=0;i<10;i++)
			a_ptr[i]=i=10-i;
		 


	 
 
	//MPI_Bcast(a_ptr, 10, MPI_FLOAT, 2, MPI_COMM_WORLD);
 


}

int main(int argc, char **argv)
{


	const int TAG = 1;
	MPI_Status status;
	int  numprocs, rank;
	int rc;

	int array[10];
	int *my_array = NULL;
	int sorted_array[] = { 0,1,2,3,4,5,6,7,8,10,12,35 };
	int length = 10;



	rc = MPI_Init(&argc, &argv);
	if (rc != MPI_SUCCESS) {
		printf("Error starting MPI program. Terminating.\n");
		MPI_Abort(MPI_COMM_WORLD, rc);
	}

	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);



	Get_data2(array, length, rank);




	if (rank == ROOT_RANK)
	{

		sequential_odd_even_sort(array, length);

		
		for (int i = 0; i < length; i++)
		{
			cout << array[i] << " ";

		}
	}


	MPI_Finalize();


	return 0;
}



