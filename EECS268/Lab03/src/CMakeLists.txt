# Author: 	Robert Hümmer
# Date:		25.12.2016

# Set the compilation flags to report all warnings and enable debugging 
# in all the generated obj files and executable
set( CMAKE_C_FLAGS "-Wall -g" )

# The following command "file GLOB" will search for all files within the current directory
# that match the specified expressions (*.c *.cpp) and assign the resulting files 
# to the variable SRCS. 
# => SRCS is a list of all C and CPP sourc and header files in the current directory
file( GLOB SRCS *.c *.cpp )

# Define the target application executable (named ...) 
# and the list of source and header files needed for the executable
add_executable( MathTools ${SRCS} )
