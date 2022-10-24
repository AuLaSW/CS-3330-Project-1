cmake_minimum_required(VERSION 3.5)
project(Week_1_Austin_Swanlaw)

#target_link_libraries(Week_1_Austin_Swanlaw PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
#file(GLOB HEADERS "include/*.hpp")
#add_library(include ${HEADERS})
#add_subdirectory(include)
#target_link_libraries(Week_1_Austin_Swanlaw PUBLIC include)
#target_include_directories(Week_1_Austin_Swanlaw PUBLIC
#"${PROJECT_BINARY_DIR}"
#"${PROJECT_SOURCE_DIR}/include"
#)
include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(Week_1_Austin_Swanlaw ${SOURCES})
