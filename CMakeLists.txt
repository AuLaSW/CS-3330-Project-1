cmake_minimum_required(VERSION 3.5)
project(Week_1_Austin_Swanlaw)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(Week_1_Austin_Swanlaw ${SOURCES})

target_link_libraries(Week_1_Austin_Swanlaw ${library_LIBRARIES})

