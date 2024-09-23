cmake_minimum_required(VERSION 3.26.3)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(G_Engine)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")    
set(CMAKE_CXX_FLAGS_RELEASE "-O3")     

message("Build type: ${CMAKE_BUILD_TYPE}")

find_package(OpenGL REQUIRED)

include_directories(include
                    external/glfw/include
                    external/glad/include
                    external/stb_image/include
                    external/GLM)


add_subdirectory(src)
add_subdirectory(src/Test)
add_subdirectory(src/Render/OpenGL)
add_subdirectory(external/glfw)
add_subdirectory(external/glad)
add_subdirectory(external/GLM)
add_subdirectory(external/stb_image)

