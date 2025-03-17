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
void custom_sum(void *in, void *inout, int *len, MPI_Datatype *dtype);
int main(int argc, char **argv)
{
    int num_arg = check_args(argc, argv); 
    int* my_vector = malloc(num_arg * sizeof(int))
    if (my_vector == NULL) 
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(-1);
    }
    int min_value = 1;
    int max_value = 10000;
    initialise_vector(my_vector, num_arg, min_value, max_value); 
    int rank, size;
    MPI_Init(&argc, &argv);   
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
    MPI_Comm_size(MPI_COMM_WORLD, &size); 
    if (rank == 0) 
    {
        printf("Vector elements are:\n");
        print_vector(my_vector, num_arg);
    }
    int local_sum = sum_vector(my_vector, num_arg / size); 
    int total_sum = 0;
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0) 
    {
        printf("Predefined MPI_SUM Total Sum: %d\n", total_sum);
    }
    MPI_Op custom_op;
    MPI_Op_create(custom_sum, 1, &custom_op); 
    int custom_total_sum = 0;
    MPI_Reduce(&local_sum, &custom_total_sum, 1, MPI_INT, custom_op, 0, MPI_COMM_WORLD);
    if (rank == 0) 
    {
        printf("Custom MPI Operation Total Sum: %d\n", custom_total_sum);
    }
    MPI_Op_free(&custom_op);

    free(my_vector); 
    MPI_Finalize(); 
    return 0;
}

int sum_vector(int vector[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += vector[i];
    }
    return sum;
}

void custom_sum(void *in, void *inout, int *len, MPI_Datatype *dtype)
{
    int *in_data = (int *)in;
    int *inout_data = (int *)inout;

    for (int i = 0; i < *len; i++) 
    {
        inout_data[i] += in_data[i];  
    }
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
