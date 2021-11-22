#include<iostream>
#include<mpi.h>
using namespace std;
int ar[] = { 16,15,10,2,6,9,10,0,1,4,2,6,36,3,5,3 };
int arr[16];
void odd_even_sort(int init,int end)
{
	int phase, i, temp;
	for (phase = init; phase <=end; phase++)
	{
		if (phase % 2 == 0)
		{

			for (i = init+1; i <= end; i += 2)
			{
				if (ar[i - 1] > ar[i])
				{
					temp = ar[i];
					ar[i] = ar[i - 1];
					ar[i - 1] = temp;
				}

			}
		}
		else
		{
			for (i = init+1; i <= end - 1; i += 2)
			{
				if (ar[i] > ar[i + 1])
				{
					temp = ar[i];
					ar[i] = ar[i + 1];
					ar[i + 1] = temp;
				}
			}
		}

	}
}
void odd_even_sort_display( int init, int end,int my_rank)
{
	for (int i =init; i <= end; i++)
	{
		cout << "Sorted list from " << my_rank << "  is " << ar[i] << endl;
		arr[i] = ar[i];

	}
}

int main()
{
	int my_rank;
	int p;
	int n=16;

	
	
	int local_init;
	int local_end;
	int local_n;
	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	local_n = n / p;
	local_init = my_rank*local_n;
	local_end = local_init + (local_n-1);
	odd_even_sort( local_init, local_end);
	odd_even_sort_display( local_init, local_end, my_rank);

	
	cout << "Sorted list from "<<my_rank<<":";

	for (int i =my_rank*local_n; i <(my_rank+1)*local_n; i++)
	{
		 cout  << "  " << ar[i]<<" ";

	}
	 
 


MPI_Finalize();

/*for (int i = 0; i < n; i++)
{
	cout << "  " << arr[i];

}*/

	return 0;
}