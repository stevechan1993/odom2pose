cmake_minimum_required(VERSION 2.8.3)
project(odom2pose)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11 -march=native -DEIGEN_DONT_PARALLELIZE")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3 -Wall")

find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
    nav_msgs
    geometry_msgs
    image_transport
    sensor_msgs
    cv_bridge
    pcl_ros
    )

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(Eigen3  REQUIRED)
include_directories(
    ${catkin_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIR}
    )

catkin_package(
    )

add_executable(odom2pose
    src/main.cpp
    )


target_link_libraries(odom2pose
    ${catkin_LIBRARIES}
)    
