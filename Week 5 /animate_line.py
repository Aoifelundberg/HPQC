import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import pandas as pd
import math as m
import random

from pathlib import Path

def generate_path(home_folder = str(Path.home()), subfolder = '/data/', basename = 'output', extension = 'txt'):
   
    output_folder = home_folder + subfolder  
    filename = basename + '.' + extension  
    output_path = output_folder + filename  
    return output_path

def execute_time_step(rope, y_positions, time):
  
    # calculates the length of the string being simulated
    points = len(y_positions)

    # creates a copy of the current positions of the points on the string
    new_positions = np.copy(y_positions[0:(points-1)])

    y_positions[1:points]=new_positions

    # updates the driver
    y_positions[0] = np.sin(time*2*np.pi)

    # updates the plotted data in the animation
    rope.set_ydata(y_positions)


def reset_plots(rope, y_positions):
    
    # Calls the initial function to set up the string
    x_positions, y_positions = configure_rope()

    # sets the data for the rope to the initial value
    rope.set_data(x_positions, y_positions)


def animate(time, rope, y_positions):
    # if the time has looped around to 0.
    if time == 0:
        # reset the plot and data to show the initial condition 
        reset_plots(rope, y_positions)

    # execute the update operation 
    execute_time_step(rope, y_positions, time)

    # return a tuple of plots (lists of Line2D)
    return rope,


def configure_animation(run_time = 5, fps = 25, end_frame=True):
 
    # calculates the total number of frames in the animation
    frame_count = run_time * fps + end_frame

    # calculates the interval in milliseconds between frames, minimum 1
    interval = max([int(1000 / fps), 1])

    # calculates the time step in seconds to be used between frames
    time_step = interval / 1000

    # creates a numpy array of the times in the animation
    times = np.linspace(0., run_time, int(frame_count))

    # returns a tuple with the times, interval and frames per second
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


def main():
    # sets up the variables
    times, interval, fps = configure_animation()

    # sets up the points on the string 
    x_positions, y_positions = configure_rope()

    # configures the initial state of the plot
    fig, rope = configure_plot(x_positions, y_positions)

    # initialises the python animation 
    ani = animation.FuncAnimation(fig, animate, times, interval=interval, blit=True, # mandatory animation arguments
                                  fargs=(rope, y_positions)) 

    # saves the animation to disk
    filename = generate_path(basename = 'animate_string', extension = 'gif')
    ani.save(filename=filename, writer="pillow", fps=fps)


if __name__ == "__main__":
    main() 
