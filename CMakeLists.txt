cmake_minimum_required(VERSION 3.26.3)
project(G_Engine)


# custom variables
set(LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib")
include_directories(include)

add_subdirectory(src/Test)

add_executable(G_engine src/main.cpp)

target_link_libraries(G_engine Test)

# for third party library
file(GLOB EXTERN_LIB "${CMAKE_SOURCE_DIR}/extern/*")
foreach (LIB EXTERN_LIB)
    if (IS_DIRECTORY ${LIB})
        message(STATUS "Adding external library: ${LIB}")
        add_subdirectory(${LIB})
        if(IS_DIRECTORY "${LIB}/include")
            message(STATUS "Adding include directory: ${LIB}/include")
            include_directories("${LIB}/include")
        endif()
    endif()
endforeach()