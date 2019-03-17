cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project( LaneDetector )

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( lane_detector main.cpp lane_detector.cpp)

target_link_libraries( lane_detector ${OpenCV_LIBS} )