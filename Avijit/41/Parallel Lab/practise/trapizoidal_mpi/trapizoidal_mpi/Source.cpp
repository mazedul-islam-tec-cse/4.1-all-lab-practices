#include <stdio.h>
#include <mpi.h>
#include<iostream>
using namespace std;
float f(float x);
void Get_data2(float* a_ptr, float* b_ptr, int* n_ptr, int my_rank);
float Trap(float local_a, float local_b, int local_n, float h); /* Calculate local integral */
int main(int argc, char** argv) {
	int my_rank; /* My process rank */
	int p; /* The number of processes */
	float a; /* Left endpoint */
	float b; /* Right endpoint */
	int n; /* Number of trapezoids */
	float h; /* Trapezoid base length */
	float local_a; /* Left endpoint my process */
	float local_b; /* Right endpoint my process */
	int local_n; /* Number of trapezoids for */
				 /* my calculation */
	float integral; /* Integral over my interval */
	float total; /* Total integral */
	int source; /* Process sending integral */
	int dest = 0; /* All messages go to 0 */
	int tag = 0;
	MPI_Status status;
	/* Let the system do what it needs to start up MPI */
	MPI_Init(&argc, &argv);
	/* Get my process rank */
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	/* Find out how many processes are being used */
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	Get_data2(&a, &b, &n, my_rank);
	h = (b - a) / n; /* h is the same for all processes */
	local_n = n / p; /* So is the number of trapezoids */
					 /* Length of each process' interval of
					 * integration = local_n*h. So my interval
					 * starts at: */
	local_a = a + my_rank*local_n*h;
	local_b = local_a + local_n*h;
	integral = Trap(local_a, local_b, local_n, h);
	/* Sum up the integrals calculated by each process */
	MPI_Reduce(&integral, &total, 1, MPI_FLOAT,
		MPI_SUM, 0, MPI_COMM_WORLD);
	/* Print the result */
	if (my_rank == 0) {
		printf("With n = %d trapezoids, our estimate\n",
			n);
		printf("of the integral from %f to %f = %f\n",
			a, b, total);
	}
	/* Shut down MPI */
	MPI_Finalize();
	return 0;
}
void Get_data2(
	float* a_ptr,
	float* b_ptr,
	int* n_ptr,
	int my_rank) {
	if (my_rank == 0) {
		printf("Enter a, b, and n\n");
		*a_ptr = 2.0;
		*b_ptr = 10.0;
		*n_ptr = 4;

	}
	MPI_Bcast(a_ptr, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
	MPI_Bcast(b_ptr, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
	MPI_Bcast(n_ptr, 1, MPI_INT, 0, MPI_COMM_WORLD);
}

//Function for Calculating the area in local process
float Trap(
	float local_a,
	float local_b,
	int local_n,
	float h) {
	float integral;
	float x;
	int i;

	integral = (f(local_a) + f(local_b)) / 2.0;
	x = local_a;
	for (i = 1; i <= local_n - 1; i++) {
		x = x + h;
		integral = integral + f(x);
	}
	integral = integral*h;
	return integral;
}
float f(float x) {
	float return_val;
	return_val = x*x;
	return return_val;
}














