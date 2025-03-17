#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>
int check_args(int argc, char **argv);
void initialise_vector(int vector[], int size, int min, int max);
void print_vector(int vector[], int size);
int sum_vector(int vector[], int size);
int find_max(int vector[], int size);
int find_min(int vector[], int size);
double find_average(int vector[], int size);
int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    int my_rank, num_procs;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    int num_arg = check_args(argc, argv);
    int* my_vector = malloc(num_arg * sizeof(int));
    if (my_vector == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(-1);
    }

    int min_value = 1;
    int max_value = 10000;
    if (my_rank == 0)
    {
        initialise_vector(my_vector, num_arg, min_value, max_value);
        printf("Vector elements (from process %d):\n", my_rank);
        print_vector(my_vector, num_arg);
    }
    MPI_Bcast(my_vector, num_arg, MPI_INT, 0, MPI_COMM_WORLD);
    int my_sum = sum_vector(my_vector, num_arg);
    int total_sum;
    MPI_Reduce(&my_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (my_rank == 0)
    {
        printf("Total sum: %d\n", total_sum);
    }
    free(my_vector);
    MPI_Finalize();
    return 0;
}
int sum_vector(int vector[], int size)
{
    int sum = 0;

    // Iterates through the vector
    for (int i = 0; i < size; i++)
    {
        sum += vector[i];
    }

    return sum;
}
void initialise_vector(int vector[], int size, int min, int max)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        vector[i] = rand() % (max - min + 1) + min;
    }
}

void print_vector(int vector[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", vector[i]);
    }
    printf("\n");
}

int check_args(int argc, char **argv)
{
    int num_arg = 0;

    if (argc == 2) 
    {
        num_arg = atoi(argv[1]);
    }
    else 
    {
        fprintf(stderr, "ERROR: You did not provide a numerical argument!\n");
        fprintf(stderr, "Correct use: %s [NUMBER]\n", argv[0]);
        exit(-1);
    }
    return num_arg;
}
