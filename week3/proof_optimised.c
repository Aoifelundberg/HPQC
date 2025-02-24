#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

// function declarations
int check_args(int argc, char **argv);

int main(int argc, char **argv) 
{
	// declare and initialise error handling variable
	int ierror = 0;

	if (argc != 2)
	{
		fprintf(stderr, "ERROR: You did not provide a numerical argument!\n");
        	fprintf(stderr, "Correct use: mpicc -n 4 proof [NUMBER]\n");
        	exit(-1);
	
	}

	int num_arg = atoi(argv[1]);
	
	// intitalise MPI
	ierror = MPI_Init(&argc, &argv);

	// declare and initialise rank and size varibles
	int my_rank, uni_size;
	my_rank = uni_size = 0;

	// gets the rank and world size
	ierror = MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	ierror = MPI_Comm_size(MPI_COMM_WORLD, &uni_size);

 	if (uni_size < 2) 
	{
        	fprintf(stderr, "Unable to communicate with fewer than 2 processes.\n");
        	exit(-1);
	}
	
	if (my_rank == 0)
	{
		int output_sum = (num_arg*((uni_size - 1)* uni_size /2));
		printf("The combined result is %d\n", output_sum);
	}
		
	// finalise MPI
	ierror = MPI_Finalize();
	return 0;
}
 






