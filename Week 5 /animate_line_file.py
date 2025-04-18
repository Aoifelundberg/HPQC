import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import pandas as pd
import math as m
import random

from pathlib import Path
import sys

def generate_path(home_folder = str(Path.home()), subfolder = '/data/', basename = 'output', extension = 'txt'):
   
    output_folder = home_folder + subfolder  # appends a subdirectory within it.
    filename = basename + '.' + extension  # defines the filename the output is to be saved in
    output_path = output_folder + filename  # creates the output path
    return output_path

def execute_time_step(data, rope, i):
    # updates the positions
    x_positions, y_positions = extract_position(data, i=i)

    # updates the plotted data in the animation
    rope.set_data(x_positions, y_positions)
    return i


def reset_plots(rope, y_positions):
    # Calls the initial function to set up the string
    x_positions, y_positions = configure_rope()

    # sets the data for the rope to the initial value
    rope.set_data(x_positions, y_positions)


def animate(time, data, rope):
    # updates the positions
    x_positions, y_positions = extract_position(data, i=time)

    # updates the plotted data in the animation
    rope.set_data(x_positions, y_positions)
    
    # return a tuple of plots (lists of Line2D)
    return rope,


def configure_animation(frame_count = 125, fps = 25):
    # calculates the total run time in the animation
    run_time = frame_count/fps 

    interval = max([int(1000 / fps), 1])

    # calculates the time step in seconds to be used between frames
    time_step = interval / 1000

    # creates a numpy array of the times in the animation
    times = np.linspace(0., run_time, int(frame_count))

    return times, interval, fps


def configure_rope(length=50, end_point=True, step_size=1, start = 0):
    # calculates the number of points to simulate
    points = int((length/step_size) + end_point)

    # calculates the position of the end of the string
    stop = start + length

    # calculates the x-positions of the points on the string
    x_positions = np.linspace(start=start, stop=stop, num=points, endpoint=end_point)

    # sets the initial positions of the simulated points to zero
    y_positions = np.zeros(points)

    return x_positions, y_positions


def configure_plot(x_positions, y_positions):

    fig, (ax1) = plt.subplots(1, 1)
    fig.suptitle('Simulation of Vibrations in a string')
    ax1.set_ylim(-1.1, 1.1)
    rope, = ax1.plot(x_positions, y_positions, "o", markersize=5, color="green", label="points on string")
    ax1.legend(handles=[rope], bbox_to_anchor=(0, 0), loc='upper left')
    return fig, rope


def get_data(filename, other=2):
    try:
        data = pd.read_csv(filename, skipinitialspace=True)
    except FileNotFoundError:
        # explains what has gone wrong
        print("The file you have specified, {} does not exist. Have you given the correct path to the file?".format(filename))
        # exits with error status
        exit(-1)

    # calculates how many positions have been measured
    num_positions = len(data.columns)-other

    # calculates how many samples were taken
    num_times = len(data)
    
    return data, num_positions, num_times


def extract_position(data, i=0, other=2):

    row = data.iloc[i]
    y_positions = np.array(row[other:]).flatten()
    x_positions = np.arange(len(row)-other)
    return x_positions, y_positions


def get_file_name(extension="txt"):
    try:
        filename = sys.argv[1]
    except IndexError:
        # explain the error
        print("You must specify a file to plot.\nCorrect Useage: \n\t{} [FILENAME].{}".format(sys.argv[0], extension))
        # exit the program with error status
        exit(-1)

    if ((filename.split('.')[-1])!=extension):
        print("The file you have specified, {} does not appear to be a {} file.".format(filename, extension))
        # exit the program with error status
        exit(-1)

    return filename


def main():
    filename = get_file_name("csv")
    data, num_positions, num_times = get_data(filename)
    times, interval, fps = configure_animation(frame_count=num_times)
    x_positions, y_positions = extract_position(data)
    fig, rope = configure_plot(x_positions, y_positions)
    ani = animation.FuncAnimation(fig, animate, num_times, interval=interval, blit=True, # mandatory animation arguments
                                  fargs=(data, rope)) # arguments to the animate function

    filename = generate_path(basename = 'animate_string_file', extension = 'gif')
    ani.save(filename=filename, writer="pillow", fps=fps)


if __name__ == "__main__":
    main() 
