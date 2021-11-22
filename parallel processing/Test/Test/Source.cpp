#include <iostream>
#include <mpi.h>
using namespace std;
void main(int argc, char *argv[])
{
	MPI_Init(&argc, &argv);
	cout << "Hello World!" << endl;
	MPI_Finalize();
}
