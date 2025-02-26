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

