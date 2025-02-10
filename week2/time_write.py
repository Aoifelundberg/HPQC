import sys
import time
from datetime import datetime


def main():
    output = 0
    fp = open("data/time_py.txt", 'w')

    try:
        in_arg = int(sys.argv[1])
    except: 
        raise Exception("Incorrect arguments.\nUsage: python time_print.py [NUM]\ne.g.\npython time_print.py 23")

    start_time = datetime.now()
    for i in range(in_arg):
    	fp.write(str(i))
    	fp.write("\n")
    end_time = datetime.now()

    run_time = end_time - start_time
    print("Time taken:{}".format(end_time-start_time))
    

    fp.write("Time taken:{}".format(end_time-start_time))
    fp.close


if __name__ == "__main__":
    main()
