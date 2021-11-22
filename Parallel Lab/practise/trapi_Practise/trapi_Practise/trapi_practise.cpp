#include <stdio.h>
#include<string.h>
#include<mpi.h>
const int Max_string = 100;
int main()
{
	char greeting[]= "hello1";;
	int comm_sz;
	int my_rank;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	if (my_rank != 0)
	{
		
		MPI_Send(greeting, strlen(greeting) + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
		printf("Greeting from process %d of  %d !\n", my_rank, comm_sz);

	}
	else
	{
		printf("Greeting from process %d of  %d !\n", my_rank, comm_sz);
		for (int q = 1; q < comm_sz; q++) {
			MPI_Recv(greeting, Max_string, MPI_CHAR, q, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
			printf("%s\n", greeting);
		}
		
	}
	MPI_Finalize();
	return 0;




}


