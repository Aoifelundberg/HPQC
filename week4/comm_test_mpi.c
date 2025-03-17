#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) 
{
	int ierror = 0;
	int my_rank, uni_size;
	my_rank = uni_size = 0;
	ierror = MPI_Init(&argc, &argv);
	ierror = MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
	ierror = MPI_Comm_size(MPI_COMM_WORLD,&uni_size);
	int send_message, recv_message, count, dest, source, tag;
	send_message = recv_message = dest = source = tag = 0;
	count = 1;
	MPI_Status status;
	
	if (uni_size > 1)
	{
		if (0 == my_rank)
		{
			for (int their_rank = 1; their_rank < uni_size; their_rank++)
        {
				source = their_rank;
				MPI_Recv(&recv_message, count, MPI_INT, source, tag, MPI_COMM_WORLD, &status);
				printf("Hello, I am %d of %d. Received %d from Rank %d\n",
						my_rank, uni_size, recv_message, source);
			} 
		} 
		else 
		{
			dest = 0; // destination is root
			send_message = my_rank * 10;
			MPI_Send(&send_message, count, MPI_INT, dest, tag, MPI_COMM_WORLD);
                        printf("Hello, I am %d of %d. Sent %d to Rank %d\n",
                                         my_rank, uni_size, send_message, dest);

		} 
	} 
	else
	{
		printf("Unable to communicate with less than 2 processes. MPI communicator size = %d\n", uni_size);
	}
	ierror = MPI_Finalize();
	return 0;
}
