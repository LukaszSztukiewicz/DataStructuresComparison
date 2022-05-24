#!/bin/bash
projectname="$1"

#add dependencies
cd lib && git clone https://github.com/google/googletest.git
cd ../

echo "
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

# Set the name of the project as THIS variable
set(THIS ${projectname})
project(\${THIS})

#source headers
include_directories(src)

#dependencies
add_subdirectory(lib/googletest)

#our subdirectories (goes into subdirectory and searches for CMakeLists.txt there)
add_subdirectory(src)
add_subdirectory(test)
" > CMakeLists.txt

echo "prun (){
    ./bin/${projectname}_run
}
export -f prun" >> ~/.bashrc

echo "ptest (){
    ./bin/${projectname}_test
}
export -f ptest" >> ~/.bashrc

echo "alias prun=./bin/${projectname}_run" >> ~/.bashrc

echo "alias ptest=./bin/${projectname}_test" >> ~/.bashrc


chmod +x ./scripts/bash/mf.sh
./scripts/bash/mf.sh ${projectname}


#run build
cmake .
make