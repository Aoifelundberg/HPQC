# Week 2
**Comparing Run Times:**

All code given from the communal GitHub repositories for this module were cloned to a personal repository named HPQC, which was connected to my own terminal, enabling me to run and test the cloned code from GitHub. The first task was to compile the code written in C, all files written in C required compiling before the file could be read effectively. This was done by typing the following into the command promt:

 **gcc PHY1090/week2/hello_world.c -o bin/hello_world**

The "hello_world" file name will change depending on what C program/file is being focused on, the example above compiles the hello_world file. Once this was done, it was possible to run the code through the command prompt by simply typing:

**time ./bin/hello_world – For files written in C**

**time python3 ./PHY1090/week2/hello_world.py – For files written in Python**

It is neccessary to compile and direct C code to Bin to allow the file to be easily read by the computer, bin will convert the C program into a binary file and enable quicker processing.
These files are simultaneously running a timing program alongside the hello_world program. The hello_world program in both C and Python, as well as the repeat_adder programs were run. All were timed and the length of time taken to run the code was printed. Repeat adder requires two inputs, which are then multiplied, the output is the resultant value. 
 
Run times for both python programs were similar as with the run times for both C programs, however when comparing the times taken for C and Python, Python is considerably slower.

For python program the system times were >= 0.008s, the user times were >= 0.019s, and the real times were >= 0.026s.
For C program the system times were = 0.000s, the user times were = 0.001s, and the real times were = 0.001s.

**Changing the code:**

The next step for this assignment was to alter the code given for time_print.py and time_print.c. The objective was to create a program that would run and measure the length of time taken to run the time_print code, output a set of results, and to then have a new program read and store the results in a text file. 
_**Time_print.py**_	
Two files were created in the directory, one which produced results of the time taken to run the time print program and one that stored and displayed the results. The final output was then saved onto the Linux server and could then be viewed. The read file was run after and the text file was produced. 
_**Time_print.c**_
The same process was implemented to obtain, store and display a time output in C as it was in Python. This was a much more simple process as the reading and storing of the text file simply required a while loop which took in the write file and displayed it. All code written in C was compiled as described before. 

Text files could be viewed by typing:
**Nano <file location/file name>**

The run times observed were relatively similar to the run times observed before altering the code, with a small but significant difference. C ultimately ran faster than Python, however, the significant time difference was emphasized when larger input values were used. When larger input values were used C greatly outperformed Python, it is evident from this that for high quantities of data C is a more convenient language to use.
 
