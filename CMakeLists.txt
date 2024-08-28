cmake_minimum_required(VERSION 3.26.3)
project(G_Engine)


# custom variables
set(LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib")
include_directories(include)

add_subdirectory(src/Test)

add_executable(G_engine src/main.cpp)

target_link_libraries(G_engine Test)