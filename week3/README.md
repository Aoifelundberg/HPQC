**Part 1:**

When the described guidlines to run hello_mpi.c are not followed the code will not run. The code was compiled and then run as per directions. Mpi commands muct be run from the command line in a diiferent fashion that serial codes, using mpicc to compile instead of gcc. Once compiled, the code is run by calling mpirun -np [argument], this is not needed for serial code.Serial code just requires the directory of the file followed by the argument. 
The program run time was processed, I found that with larger arguments the real time was almost half that of the user and sys time. For smaller inputs the real time was similar and sometimes even larger than the user and sys time.
Comparing this to the serial version of this code, the user, sys, and real time remained less variable and were generally very similar to eachother regardeless of input value. This shows that for large values of input data parallel computing can be of benefit, as the code runs faster.


**Part 2:**

**Documenting the code **
All processes, except root, will calculate a value based on ranking and the numerical argument. The rank is then multiplied by the argument. 
The root process will then collect all these values from the individual processed and compute the sum. 
Check_args accepts one argument called num_arg which is later used in the output computation. 
Check_uni_size will ensure the input universe size is valid, if the universe size is not valid the code is told to exit the process.
Check_task separates tasks carried out by each type of node, the client task will send the results of the calculation to the root. 

This code was optimised by removing some unecessary steps in the code and implementing them into the main branch instead. The prgram calculation essentially performs as follows: num_arg x (((uni_size - 1) x uni_size)/2), this formula was implemented into the main branch to cut down on uneccessary steps.

**Part 3**
The main steps of the vector_serial program is to input a value which will be checked to ensure validity using check_args, and will then return the input as a vector. 
Initialise_vector is used to initialise all the elements of the vector taken from check_args.
Stdlib.h is used for memory allocation (malloc()), conversion and termination. Malloc() is also used as a pointer allocation to store the given argument. 
sum_vector is used to sum all the elements of the vector and produce an output. 
Memory cleanup is then performed, the dynamic memory is freed using free(), this prevents memory leaks. Dynamic memory allocation allows for flexible sizing of user input and frees memory after use.

Modifying the code -  the code was made non-trivial by implementing #include <time.h>, this will ensure different results for every run of the code. A random min and max value were assigned within a certain range as per the code to initialise the vector. The program was also modified to disallow non zero vector values. Errors are now accounted for and the code no longer ouputs a zero value, instead it outputs the elements of the vector and the sum. 

Creating a parallel version - This was simply done by parallelising the initialisation and summing of the vector. The initialisign function was parallelised by adding "#pragma omp parallel for", and the summing function was parallelised by adding "#pragma omp parallel for reduction(+:sum)". I found that for very large input values the parallel version of this program performed faster than the serial. User time was significantly smaller for parallel. With small input values, the two programs performed similarly. 
