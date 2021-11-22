#include<iostream>
#include<mpi.h>
using namespace std;
int main(int argc, char *argv[])
{
	MPI_Init(&argc, &argv);
	int comm_sz;
	int my_rank;
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);


	cout << "  Hello world! from  " <<my_rank<<" of "<< comm_sz<< endl;
	MPI_Finalize();
}