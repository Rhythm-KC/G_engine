#!/bin/bash
baseOutPath="out/build"
debug="Debug"
release="Release"
debug_path="$baseOutPath/$debug"
release_path="$baseOutPath/$release"
working_dir=$(pwd)
project_name="G_engine"

usage(){
    echo "Usage: $0 [clean|build|run] [Debug|Release|no args]"
    echo "Commands:"
    echo "  clean      : Remove the specified build (Debug/Release) or both if no argument is given"
    echo "  build      : Build the specified configuration (Debug/Release) or both if no argument is given"
    echo "  run        : Run the built project (either Debug or Release, preference to Release if both exist)"
}

remove_dir(){
    if [ -e "$1" ] && [ -d "$1" ]; then
        echo "Removeing $1"
        rm -rf "$1"
    fi
}

build(){
    cmake -S . -B "$1" -DCMAKE_BUILD_TYPE="$2"
    cd "$1"
    make
    cd "$working_dir"
}

run(){
    "$1/src/$project_name"
}


if [ "$1" = "clean" ]; then
    if [ "$2" = "$debug" ]; then
        remove_dir $debug_path
    elif [ "$2" = "$release" ]; then
        remove_dir $release_path
    elif [ -z "$2" ]; then
        remove_dir $debug_path
        remove_dir $release_path
    else
        echo "Don't reconginze argument $2.\n Can only take Debug/relase/[no args]"
    fi
elif [ "$1" = "build" ]; then
    if [ "$2" = "$debug" ]; then
        build $debug_path $debug
    elif [ "$2" = "$release" ]; then
        build $release_path $release
    elif [ -z "$2" ]; then
        echo "Building Debug"
        build $debug_path $debug
        echo "Building Release"
        build $release_path $release
    else
        echo "Don't reconginze argument $2.\n Can only take Debug/relase/[no args]"
    fi
elif [ "$1" = "run" ]; then
    if [ -e "$release_path" ]; then
        echo "Runing release"
        run $release_path
    elif [ -e "$debug_path" ]; then
        echo "Runing debug"
        run $debug_path
    else
        echo "Project is not build try ./G_engine.sh build"
    fi
else
    usage
    exit 1
fi

