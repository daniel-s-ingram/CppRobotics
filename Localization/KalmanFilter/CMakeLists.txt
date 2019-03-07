cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project( KalmanFilter )

find_package( OpenCV REQUIRED )
find_package( Eigen3 REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} ${Eigen3_INCLUDE_DIRS} )

add_executable( kalman main.cpp simulator.cpp robot.cpp filter.cpp)

target_link_libraries( kalman ${OpenCV_LIBS} ${Eigen3_LIBS} )