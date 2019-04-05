cmake_minimum_required (VERSION 3.0)
project(test_MathTools_Project) 

# Setup CMake to run tests
enable_testing()

# indicates the location of the boost installation tree
set( BOOST_INCLUDE_DIRS $boost_installation_prefix/include)

# replace XX with the version you have
set(Boost_ADDITIONAL_VERSIONS "1.62" "1.62.0")

# find boost, trigger an error otherwhise
find_package(Boost 1.60 REQUIRED COMPONENTS unit_test_framework)

# add the executable
add_executable(test_MathTools test_MathTools.cpp ../src/MathTools.cpp)

# indicates the include paths
target_include_directories(test_MathTools PRIVATE ${Boost_INCLUDE_DIRS})
 
# indicates the shared library variant
target_compile_definitions(test_MathTools PRIVATE "BOOST_TEST_DYN_LINK=1")

# indicates the link paths
target_link_libraries(test_MathTools ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

# declares a test with our executable
add_test(NAME test1 COMMAND test_MathTools)
