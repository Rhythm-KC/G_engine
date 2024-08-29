cmake_minimum_required(VERSION 3.26.3)
project(G_Engine)


# custom variables
set(LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib")
include_directories(include
                    external/glfw/include)

add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(src/Test)
add_subdirectory(external/glfw)

target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/external/glfw/src)

target_link_libraries(${PROJECT_NAME}
                        Test 
                        glfw)