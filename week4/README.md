## Part 1 ##
# Step 1 # 
When the code comm_test.mpi is run the send and recieve processes are performed in no specific order. The more processors assigned to the code, there are more send processes performed before recieve. The recieve processes are always set to Rank 0, and the recieve are ranked from 1 - no.processors. The send command does not opperate in order and sends is a sporadic manner whereas the ranks are always recieved in order from smallest input to largest 

# Step 2 #
The code was functionalised by segmenting the processes and assigning specific functions to each process. These functions were then implemented in the main function. This makes the code more efficient and managable. Each function performs a single specified task. 

# Step 3 #
The code was modified to include: MPI_Ssend(), MPI_Bsend(), MPI_Rsend() and MPI_Isend(). Upon implementing these changes, the code does appear to send majority of messages before receiving them, however there are still one or two messages being received before being sent. This issue is more prevelant with larger numbers of processors. With less than 10 processors there is generally only one error, with more than 10 the send and receive processes are much more sporadic and the performance is similar to the performance of the program before functionalisation. Based on this, it appears that the modified code would perform better as long as the input number of processors is relatively low, as there are still less errors than previously. 

# Step 4 # 
After adding in code to time the function it was found that the timing was relatively inconsistant. Times were always <0.0004s, however there was a wide range of time values. More processors did not appear to impact the run time, in fact run time was considerably less for larger inputs in some cases. 
