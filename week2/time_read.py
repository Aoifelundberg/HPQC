import sys
import time


start_time = time.time()

file = open("data/time_py.txt", "r")

end_time = time.time()

run_time = end_time - start_time
    

file.close()

print(run_time)

