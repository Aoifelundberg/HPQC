## Part 1 ##
# Step 1 # 
When the code comm_test.mpi is run the send and recieve processes are performed in no specific order. The more processors assigned to the code, there are more send processes performed before recieve. The recieve processes are always set to Rank 0, and the recieve are ranked from 1 - no.processors. The send command does not opperate in order and sends is a sporadic manner whereas the ranks are always recieved in order from smallest input to largest 

# Step 2 #
The code was functionalised by segmenting the processes and assigning specific functions to each process. These functions were then implemented in the main function. This makes the code more efficient and managable. Each function performs a single specified task. 

# Step 3 #
The code was modified to include: MPI_Ssend(), MPI_Bsend(), MPI_Rsend() and MPI_Isend(). Upon implementing these changes, the code does appear to send majority of messages before receiving them, however there are still one or two messages being received before being sent. This issue is more prevelant with larger numbers of processors. With less than 10 processors there is generally only one error, with more than 10 the send and receive processes are much more sporadic and the performance is similar to the performance of the program before functionalisation. Based on this, it appears that the modified code would perform better as long as the input number of processors is relatively low, as there are still less errors than previously. 

# Step 4 # 
After adding in code to time the function it was found that the timing was relatively inconsistant. Times were always <0.0004s, however there was a wide range of time values. More processors did not appear to impact the run time, in fact run time was considerably less for larger inputs in some cases. 


## Part 2 ##
A program named pingpong.c was created which implemented the pseudocode logic as described in the assignment. This program took an input number of pings and calculated the elapsed time and average time per round trip, using send and receive functions. 

2 processors were required to run this program. The number of pings were varied and the output time value did seem to converge slightly with much larger inputs. The smaller the imput number of pings were, the quicker the program ran. 

This program was then modified to take two inputs, this was done in order to create and initialise an array of the variable size. The array was transmitted back and forth between client and root as required, like a ping pong action. The array used incremental values between 8B and 2MiB, the number of elements required were calculated by dividing the number of Bytes by 4. It was divided by 4 as an integer value is 4 Bytes. The formula would be: Total number of elements = Data size/size of element. The number of input elements were plotted against the total time elapsed and the average time taken for one round trip. This was done to find the latency and bandwidth. Latency was detemined by the Y-intercept when the time per round trip was plotted against the number of elements. In this case the latency was 0.00015s. Bandwidth was detemined from the slope of the line created when the total elapsed time taken to run the program was plotted against the number of elements. This bandwidth was determined to be 7.7E-09.
