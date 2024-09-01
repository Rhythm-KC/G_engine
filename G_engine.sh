#! /bin/sh
if [ "$1" = "clean" ] || [ "$1" == "-c" ]; then
    rm -rf out/build
    echo "out/build removed"
elif [ "$1" = "config" ]; then
    cmake -D GLFW_BUILD_DOCS=OFF -S . -B out/build;
elif [ "$1" = "run" ]; then
    cd out/build/src; ./G_engine
elif [ "$1" = "make" ]; then
    cd out/build;
    make;
elif [ "$1" = "build" ]; then
    cmake -D GLFW_BUILD_DOCS=OFF -S . -B out/build;
    cd out/build;
    make;
else
    echo "Usage run.sh [clean config make run build] 
    clean: clears the out dir to make a fresh build 
    config: Configures cmake
    make: makes the build i.e compiles and link 
    build: configures cmake and then makes the application
    run: Run the G_engine application"
fi