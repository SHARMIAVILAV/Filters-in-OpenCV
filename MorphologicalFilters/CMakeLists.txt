cmake_minimum_required(VERSION 3.13)
# project(first)

set(CMAKE_CXX_STANDARD 11)

# add_executable(first first.cpp)
# # Add the include directories for your project
# target_include_directories(first PRIVATE opencv2/highgui/highgui.hpp)

cmake_minimum_required(VERSION 2.8)




project( filters )

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( filters filters.cpp )

target_link_libraries( filters ${OpenCV_LIBS})