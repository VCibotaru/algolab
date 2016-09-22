#!/bin/bash

# usage: $0 - project name

if [ -z $1 ]; then
    echo "Please provide a name for the project"
else 
    echo "Creating project $1"
fi

project_name=$1
test_folder=$project_name/tests
main_file_path=$project_name/main.cpp
build_script_path=$project_name/build.sh
test_script_path=$project_name/test.sh

mkdir $project_name
mkdir $test_folder

# copy the stub main.cpp file
cp ./stub-main.cpp $main_file_path

# copy the build script
cp ./build.sh $build_script_path
chmod +x $build_script_path

# copy the testing script
cp ./test.sh $test_script_path
chmod +x $test_script_path

echo "`pwd`/$project_name"
