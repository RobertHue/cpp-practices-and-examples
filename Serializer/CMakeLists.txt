# Author:	Robert Huemmer
cmake_minimum_required (VERSION 3.0)

# Define the project name
project(Serializer_Test) 

# Set the compilation flags to report all warnings and enable debugging 
# in all the generated obj files and executable
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


# hdf5 related linker flags
set(HDF5_COMPILE_FLAGS  "-I/usr/include/hdf5/serial -D_LARGEFILE64_SOURCE -D_LARGEFILE_SOURCE -Wdate-time -D_FORTIFY_SOURCE=2 -g -O2 -fstack-protector-strong -Wformat -Werror=format-security")
set(HDF5_LINKER_FLAGS   "-L/usr/lib/x86_64-linux-gnu/hdf5/serial /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_hl_cpp.a /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.a /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_hl.a /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.a -Wl,-Bsymbolic-functions -Wl,-z,relro -lpthread -lsz -lz -ldl -lm -Wl,-rpath -Wl,/usr/lib/x86_64-linux-gnu/hdf5/serial")

# append the hdf5 flags to the compiler and linker
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${HDF5_COMPILE_FLAGS}" )
set( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${HDF5_LINKER_FLAGS}" )

# boost and hdf5 related
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED OFF)   
set(Boost_USE_STATIC_RUNTIME OFF)
set(Boost_ADDITIONAL_VERSIONS "1.62" "1.62.0")

# find boost and hdf5, trigger an error otherwhise
find_package(Boost 1.62 REQUIRED COMPONENTS serialization)
find_package(HDF5)


if( Boost_FOUND AND HDF5_FOUND )
    include_directories(${Boost_INCLUDE_DIRS}) 
    include_directories(${HDF5_INCLUDE_DIR})
    set(_hdf5_libs hdf5 hdf5_cpp )

    # Add a given directory to those the compiler uses to search for include files
    # include_directories( include_dir )

    # Add a subdirectory to the project. The CMakeLists.txt in that 
    # subdirectory will be used for further setting up  the project.
    # add_subdirectory( src )
    # add_subdirectory( tests )

    # The following command "file GLOB" will search for all files within the current directory
    # that match the specified expressions (*.c *.cpp) and assign the resulting files 
    # to the variable SRCS. 
    # => SRCS is a list of all C and CPP sourc and header files in the current directory
    file( GLOB SRCS *.c *.cpp *.cc )

    # Define the target application executable (named ...) 
    # and the list of source and header files needed for the executable
    add_executable( Serializer_Test ${SRCS} )
    target_link_libraries( Serializer_Test ${Boost_LIBRARIES} ${_hdf5_libs} )
endif()
