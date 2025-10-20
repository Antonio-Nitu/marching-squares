# Marching Squares Contour Generator

Author: Nitu Andrei-Antonio  
Version: 1.0  

This program is a command-line tool written in C that generates contour maps from PPM (Portable Pixmap) images using the Marching Squares algorithm. It allows a user to load an image, process it to find contour lines based on a brightness threshold, and save the resulting map.

# Features

- PPM Image Support: Loads and processes square images in the plain PPM (P3) format.  
- Marching Squares Algorithm: The core feature, which converts a grayscale representation of an image into a black-and-white contour line map.  
- Intermediate Grid Visualization: Can display the intermediate binary grid used by the algorithm.  
- Image Resizing: Includes a basic nearest-neighbor scaling function to enlarge images.  
- Modular Codebase: Well-structured C code split into logical modules for readability and maintenance.  

# How it Works

The program operates in several key stages to generate the contour map:
- Image Loading (READ): The user loads a square P3 PPM image. The program stores this image in memory as a 2D array of pixels.  
- Grid Generation (GRID): The program creates a coarse, smaller binary grid (matrix of 0s and 1s) from the full-sized image. It samples the brightness of the image at regular intervals. If a sampled region's average brightness is above a defined threshold (SIGMA), it's marked as 0; otherwise, it's marked as 1.  
- Marching Squares (MARCH): The algorithm iterates through the binary grid, looking at 2x2 blocks of cells at a time.
Each 2x2 block has 16 possible combinations of 0s and 1s (e.g., all 0s, one 1, two 1s, etc.).
Each combination corresponds to a specific 4x4 pixel pattern representing a line segment (a contour).
The program replaces 4x4 blocks of the original image with these predefined contour patterns, effectively "drawing" the contour lines over the original image data.  
- Image Saving (WRITE): The user can save the modified image data (which now contains the contour map) to standard output.  

# Compilation

A Makefile is provided to compile the project. Ensure you have gcc and make installed.

- To compile the program and create the 'marching_squares' executable:  
make build

- To remove the executable and all intermediate object files:  
make clean


# Usage

The program runs as an interactive command-line tool. Once compiled, run it with:

./marching_squares

The program will then wait for your input. You can redirect input from a file or pipe output to a file using standard shell redirection.

# Commands

- READ: Loads a PPM image from standard input. The image data must immediately follow the command.

./marching_squares < commands.txt


- WRITE: Prints the current image in memory to standard output in P3 PPM format.

./marching_squares < commands.txt > output.ppm


- GRID: Calculates and prints the intermediate binary grid to the console.  
- MARCH: Applies the Marching Squares algorithm to the currently loaded image, replacing it with its contour map.  
- RESIZE: Resizes the current image to be 4 times larger.  
- INIT_CONTOUR: A utility command that prints all 16 possible 4x4 contour patterns as valid PPM images.  
- EXIT: Terminates the program.  

# Example Workflow

Here is an example of a command file (commands.txt) to process an image named input.ppm.

commands.txt:

READ  
P3  
512 512  
255  
... (pixel data for input.ppm) ...  
MARCH  
WRITE  
EXIT  

# Execution:

This will read input.ppm, apply the algorithm, and save the result to contour_map.ppm:  
cat commands.txt | ./marching_squares > contour_map.ppm

# Project Structure

The project is organized into several modules for clarity:

- main.c: The main entry point and command loop.
- GENERAL.c: Utility functions for memory allocation.
- READ.c / WRITE.c: Handles PPM image input/output.
- GRID.c: Logic for generating the binary grid from an image.
- INIT_CONTUR.c: Defines the 16 contour patterns used by the algorithm.
- MARCH.c: The core implementation of the Marching Squares algorithm.
- RESIZE.c: Image scaling functionality.
- headers/: Contains all the corresponding .h header files.
