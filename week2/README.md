# Week 2
Comparing Run Times
All code given from the communal GitHub repositories for this module were cloned to a personal repository named HPQC, which was connected to my own terminal, enabling me to run and test the cloned code from GitHub. The first task was to compile the code written in C, all files written in C required compiling before the file could be read effectively. This was done by typing the following into the command promt:
gcc PHY1090/week2/hello_world.c -o bin/hello_world
The font in blue changes depending on what c program is being focused on, the example above compiles the hello_world file. Once this was done, it was possible to run the code through the command prompt by simply typing:
time ./bin/hello_world – For files written in C
time python3 ./PHY1090/week2/hello_world.py – For files written in Python
These files are simultaneously running a timing program alongside the hello_world program. The hello_world program in both C and Python were run as well as the repeat_adder programs, all were timed and the length of time taken to run the code was printed. Repeat adder requires two inputs, which are multiplied, the output is the resultant value. The times taken to run the programs can be seen in the screenshot below. 
 
Figure 1: Example of how programs were called in the terminal
Run times for both python programs were similar as with the run times for both C programs, however when comparing the times taken for C and Python, Python is considerably slower, as can be seen in the image above. 
Changing the code
The next step for this assignment was to alter the code given for time_print.py and time_print.c. The objective was to create a program that would run and measure the length of time taken to run the time_print code, output a set of results, and to then have a new program read and store the results in a text file. 
	Time_print.py		
Two files were created in the directory, one which produced results of the time taken to run the time print program and one that stored and displayed the results. The final output was then saved onto the Linux server and could then be viewed. The read file was run after and the text file as seen below was produced. 
	Time_print.c
The same process was implemented to obtain, store and display a time output in C as it was in Python. This was a much more simple process as the reading and storing of the text file simply required a while loop which took in the write file and displayed it. All code written in C was compiled as described before. 
Text files could be viewed by typing:
Nano <file location/file name>
The run times observed were relatively similar to the run times observed before altering the code, with a small but significant difference. C ultimately ran faster than Python, however, the significant time difference was emphasized when larger input values were used. When larger input values were used C was much faster, it is evident from this that for high quantities of data C is a more convenient language to use.
 
Figure 2: time_write and time_read programs being used consecutively to produce text file on terminal
 
Figure 3: Output runtime text file for C program, input value - 2000
