## Part 1 ##
Hard coding was removed from string_wave.c and animate_line_file.py as instructed. The main features of this programs after removing hard coding are as follows:

# String wave program #
**Argument Parsing** - This means arguments are accepted from the command line and assigned to specific functions. These arguments are used to describe the number of positions on the string, number of cycles and number of samples.Check_args is used to ensure that arguments from the command line are valid.

**Timestamp Generation** - A loop is used to establish the time steps for the string wave elements at specific times. This is done using time steps and step sizes. The time step is calculated using the reciprocal of the number of samples per cycle.

**Position Updates** - This is similar to the timestep generation in that the position of the elements changes over time, the string wave is modelled on the basis that it is a SHO, the time steps are used to calculate the position of each element after a given time step. Positions are stored as an array and iterated through the function update_positions()

**CSV file writing** - The final output of this program is a csv file containing data on the positions and timestamps of the string wave elements. This csv is then passed through the animate_line_file.py program. 

**Driver Function** - The driver function is used to oscillate the string, again, teh string is modeled on the behaviour of a SHO so the output shoul dbe a sine wave. This function uses both the update position function outputs and timestamp function to model the movement of the string over time. 

# Animate line file program # 

**Argumennt Parsing** - This is used to read in data. Reads in file name, output directory, basename, extension, file type, frame count and fps. 

**Reading & Processing** - The main function of this program is to read in the csv created from the previous code and load in the vibration data using get_data(filename). Data is extracted from the csv file rows and columns and returned using pandas.dataframe to allow the data to be converted into a gif.

**Configuration** - Configure functions are used to define the total run time/frame interval & time steps, the array of points on the x axis, as well as to create a basic plot for the gif to display using matplotlib.

**Save the animation** - Lastly, this program is used to save the gif animation of the string wave as it oscillates using ani_save()


## Part 2 ## 
The previously mentioned code was parallelised using mpi funtions. This was done in the typical manner of dividing the workload of the program into seperate functions. The mpi environment was first initialises using functions like Mpi_init, Mpi_Comm_Rank, and Mpi_Comm_size. Once the environment is initialised the position data that is displayed as an array was broken up into subsections for further calculation of the position over time. Mpi send and recieve functions were utilised to set boundary conditions, this will allow the string wave to propagate. Mpi_barrier is used at the end of the program to syncronize all the processes, allowing all processes to move onto the next step at the same time. 

Using the parallel version of this code with the same arguments of 50 25 100, the program took 3m 35s(real), 3m 31s(user) and 4.9s(sys) to compute, whereas the serial version took approximately 3m 36s (real), 3m 32s (user), and 4.9s (sys). Using the same inputs as serial, the gif created was not as expected, The wave did no toscillate fully through all the points. Generally parallel programs will run quicker than serial, however, this this does not seem to be the case in this particular situation. When the input values are halfed the processing time is still in the realm of minutes but the output gif will no longer accurately depict a string wave. Instead, only some points will move while others are stationary. For this reason, it appears that the serial program outperforms the parallel program when considering the output and computing time.

