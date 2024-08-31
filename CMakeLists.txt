cmake_minimum_required(VERSION 3.26.3)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(G_Engine)


find_package(OpenGL REQUIRED)

include_directories(include
                    external/glfw/include
                    external/glew/include)


add_subdirectory(src/Test)
add_subdirectory(src/Render)
add_subdirectory(external/glfw)
add_subdirectory(src)

target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/external/glfw/src)
