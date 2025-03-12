## Part 1 ##
# Step 1 # 
When the code comm_test.mpi is run the send and recieve processes are performed in no specific order. The more processors assigned to the code, there are more send processes performed before recieve. The recieve processes are always set to Rank 0, and the recieve are ranked from 1 - no.processors. The send command does not opperate in order and sends is a sporadic manner whereas the ranks are always recieved in order from smallest input to largest 

# Step 2 #
The code was functionalised by segmenting the processes and assigning specific functions to each process. These functions were then implemented in the main function. This makes the code more efficient and managable. Each function performs a single specified task. 
