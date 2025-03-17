#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char **argv) 
{
    int my_rank, uni_size;
    int num_pings, array_size, *array = NULL;
    double start_time, end_time, elapsed_time, total_time = 0.0;
    FILE *out_file;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &uni_size);
    if (uni_size < 2) 
    {
        if (my_rank == 0)
        {
            fprintf(stderr, "At least 2 processes are required to run this program.\n");
        }
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    if (my_rank == 0) 
    {
        if (argc != 3) 
        {
            fprintf(stderr, "Usage: %s <num_pings> <array_size>\n", argv[0]);
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        num_pings = atoi(argv[1]);
        array_size = atoi(argv[2]);

        if (num_pings <= 0 || array_size <= 0)
        {
            fprintf(stderr, "num_pings and array_size must be positive integers.\n");
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        out_file = fopen("data/ping_pong_data.csv", "w");
        if (out_file == NULL) 
        {
            fprintf(stderr, "Unable to open file for writing.\n");
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        fprintf(out_file, "Message_Size,Elapsed_Time\n");
    }
    MPI_Bcast(&num_pings, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&array_size, 1, MPI_INT, 0, MPI_COMM_WORLD);
    array = (int *)malloc(array_size * sizeof(int));
    if (array == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    if (my_rank == 0) 
    {
        for (int i = 0; i < array_size; i++)
          {
            array[i] = 0; 
        }
    }
    start_time = MPI_Wtime();
    for (int ping_count = 0; ping_count < num_pings; ping_count++) 
    {
        if (my_rank == 0) 
        {
            MPI_Send(array, array_size, MPI_INT, 1, 0, MPI_COMM_WORLD);
            MPI_Recv(array, array_size, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            array[0]++;
        } else if (my_rank == 1) 
        {
            MPI_Recv(array, array_size, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            array[0]++;
            MPI_Send(array, array_size, MPI_INT, 0, 0, MPI_COMM_WORLD);
        }
    }
  
    end_time = MPI_Wtime();
    elapsed_time = end_time - start_time;
    MPI_Reduce(&elapsed_time, &total_time, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (my_rank == 0)
    {
        fprintf(out_file, "%d,%f\n", array_size, elapsed_time);
        printf("Final counter (array[0]): %d\n", array[0]);
        printf("Elapsed time: %f seconds\n", elapsed_time);
        printf("Average time per message round trip: %f seconds\n", total_time / (num_pings * (uni_size - 1))); 
    free(array);
    if (my_rank == 0) 
    {
        fclose(out_file); 
    }

    MPI_Finalize();
    return 0;
}
