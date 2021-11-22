

 #include<iostream>
#include<stdlib.h>
#include<mpi.h>
using namespace std;
void add(int x[], int y[], int z[], int local_init, int local_end)
{
	for (int i = local_init; i < local_end; i++)
	{
		z[i] = x[i] + y[i];
	}
}
void print(int z[], int local_n, int n, int my_rank) {}
int main()
{
 
	int *x=0, *y=0, *z=0;
	int n=16;
	int local_n;
	int p;
	int my_rank;
	int local_init;
	int local_end;

	int * xp;
	int *yp;
	int * zp;
	
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	local_n = n / p;

	local_init = my_rank*local_n;
	local_end = local_init + local_n;

	if (my_rank == 0) {
		x = (int *)malloc(sizeof(int)*n);
		y = (int *)malloc(sizeof(int)*n);
		z = (int *)malloc(sizeof(int)*n);

		// initialize arrays a and b with consecutive integer values
		// as a simple example
		for (int i = 0; i<n; i++)
			x[i] = i;
		for (int i = n-1; i>=0; i--)
			y[i] = n-i;
	}

	
	xp = (int *)malloc(sizeof(int)*local_n);
	yp = (int *)malloc(sizeof(int)*local_n);
	zp = (int *)malloc(sizeof(int)*local_n);
	MPI_Scatter(x, local_n, MPI_INT, xp, local_n, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(y, local_n, MPI_INT, yp, local_n, MPI_INT, 0, MPI_COMM_WORLD);
	for (int i = 0; i<local_n; i++)
		zp[i] = xp[i] + yp[i];
	//cout << "Sorted list from " << my_rank << ":";
	 
	MPI_Gather(zp, local_n, MPI_INT, z, local_n, MPI_INT, 0, MPI_COMM_WORLD);
	if (my_rank == 0)
	{
		 
		
		for (int i = 0; i < n; i++)
		{
			cout <<z[i]<<" ";
		}
	 

	}
	if (my_rank = 0)
	{
		free(x);
		free(y);
		free(z);

	 }




	/*for (int i = my_rank*local_n; i <(my_rank + 1)*local_n; i++)
	{
		cout << "  " << z[i] << " ";
		//zz[i] = z[i];


	}
	if (my_rank == 0)
	{
		for (int i = 0; i <n; i++)
		{
			cout << "  " << zz[i] << " ";
			 


		}
	}*/
	free(xp);  free(yp); free(zp);

	// 9. Terminate MPI Environment and Processes
 
	MPI_Finalize();



 
	return 0;
}