#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int check_args(int argc, char **argv);
void initialise_vector(double vector[], int size, double initial);
void print_vector(double vector[], int size);
int sum_vector(int vector[], int size);
void update_positions(double* positions, int points, double time);
int generate_timestamps(double* time_stamps, int time_steps, double step_size);
double driver(double time);
void print_header(FILE** p_out_file, int points);

int main(int argc, char **argv)
{
	int points = check_args(argc, argv);
	int cycles = 5; // number of cycles to show
	int samples = 25; // sampling rate in samples per cycle
	int time_steps = cycles * samples + 1; // total timesteps
	double step_size = 1.0/samples;
	double* time_stamps = (double*) malloc(time_steps * sizeof(double));
	initialise_vector(time_stamps, time_steps, 0.0);
	generate_timestamps(time_stamps, time_steps, step_size);

	double* positions = (double*) malloc(points * sizeof(double));
	initialise_vector(positions, points, 0.0);

	// creates a file
	FILE* out_file;
     	out_file = fopen("data/string_wave.csv","w");
	print_header(&out_file, points);

	// iterates through each time step in the collection
	for (int i = 0; i < time_steps; i++)
	{
		update_positions(positions, points, time_stamps[i]);
		fprintf(out_file, "%d, %lf", i, time_stamps[i]);
		for (int j = 0; j < points; j++)
		{
			fprintf(out_file, ", %lf", positions[j]);
		}
		fprintf(out_file, "\n");
	}

	free(time_stamps);
	free(positions);
	fclose(out_file);

	return 0;
}

void print_header(FILE** p_out_file, int points)
{
	fprintf(*p_out_file, "#, time");
	for (int j = 0; j < points; j++)
	{
		fprintf(*p_out_file, ", y[%d]", j);
	}
	fprintf(*p_out_file, "\n");
}

double driver(double time)
{
	double value = sin(time*2.0*M_PI);
	return(value);
}

void update_positions(double* positions, int points, double time)
{
        double* new_positions = (double*) malloc(points * sizeof(double));
	int i = 0;
	new_positions[i] = driver(time);
	for (i = 1; i < points; i++)
	{
		new_positions[i] = positions[i-1];
	}
	for (i = 0; i < points; i++)
        {
                positions[i] = new_positions[i];
        }
	free(new_positions);
}

int generate_timestamps(double* timestamps, int time_steps, double step_size)
{
	for (int i = 0; i < time_steps ; i++)
	{
		timestamps[i]=i*step_size;
	}	
	return time_steps;
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

void initialise_vector(double vector[], int size, double initial)
{
	for (int i = 0; i < size; i++)
	{
		vector[i] = initial;
	}
}

void print_vector(double vector[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d, %lf\n", i, vector[i]);
	}
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
		exit (-1);
	}
	return num_arg;
}
