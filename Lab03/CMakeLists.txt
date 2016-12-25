# Author:	Robert Hümmer
cmake_minimum_required (VERSION 3.0)

# Define the project name
project(MathTools_Project) 

# Add a given directory to those the compiler uses to search for include files
include_directories( include )

# Add a subdirectory to the project. The CMakeLists.txt in that 
# subdirectory will be used for further setting up  the project.
add_subdirectory( src )
add_subdirectory( tests )
