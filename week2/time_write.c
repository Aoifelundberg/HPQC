#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double to_second_float(struct timespec in_time);
struct timespec calculate_runtime(struct timespec start_time, struct timespec end_time);

int main(int argc, char **argv) 
{
	FILE *fptr;
	fptr = fopen("data/time_write.txt", "w");
	int i, input;
	i = input = 0;
	struct timespec start_time, end_time, time_diff;
	double runtime = 0.0;

	if (argc == 2)
	{
		input = atoi(argv[1]);
	}
	else
	{
		fprintf(stderr, "Incorrect arguments.  Usage: time_print [NUM]\ne.g. \n time_print 3\n");
		exit(-1);
	}
	
	timespec_get(&start_time, TIME_UTC);
	for (i = 0; i < input; i++)
	{
		printf("%d, ", i);
		fprintf(fptr,"%d",i);
	}
	fprintf(fptr,"\n");
        timespec_get(&end_time, TIME_UTC);

	time_diff = calculate_runtime(start_time, end_time);
	runtime = to_second_float(time_diff);


	printf("\n\nRuntime for core loop: %lf seconds.\n\n", runtime);
	fprintf(fptr, "%f", runtime);
	fclose(fptr);
	return 0;
}


double to_second_float(struct timespec in_time)
{
	float out_time = 0.0;
	long int seconds, nanoseconds;
	seconds = nanoseconds = 0;

	seconds = in_time.tv_sec;
	nanoseconds = in_time.tv_nsec;

	out_time = seconds + nanoseconds/1e9;

	return out_time;
}

struct timespec calculate_runtime(struct timespec start_time, struct timespec end_time)
{
	struct timespec time_diff;
	long int seconds, nanoseconds;                                                                                                       seconds = nanoseconds = 0;
	double runtime = 0.0;

	seconds = end_time.tv_sec - start_time.tv_sec;
	nanoseconds = end_time.tv_nsec - start_time.tv_nsec;

	if (nanoseconds < 0)
	{
		seconds = seconds - 1;
		nanoseconds = ((long int) 1e9) - nanoseconds;
	}

	time_diff.tv_sec = seconds;
	time_diff.tv_nsec = nanoseconds;

	return time_diff;
}

