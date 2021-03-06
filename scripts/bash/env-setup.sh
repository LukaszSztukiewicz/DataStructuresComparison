#!/bin/bash

if [ "YOUR_PROJECT_NAME_IN_QUOTATION_MARKS" = "$1" ]; then
  projectname="defaultproject"
elif [ -z "$1" ]; then
  projectname="defaultproject"
else
  projectname="$1"
fi

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

prun="prun (){
    ./bin/${projectname}_run
}" 

ptest="ptest (){
    ./bin/${projectname}_test
}"

#check what type of shell you are using and add the functions to the shell profile
if [ -f ~/.zshrc ]; then
    if ! grep -q "prun" ~/.zshrc; then
        echo ${prun} >> ~/.zshrc
        echo ${ptest} >> ~/.zshrc
        . ~/.zshrc
    fi

elif [ -f ~/.bashrc ]; then
    if ! grep -q "prun" ~/.bashrc; then
        echo ${prun} >> ~/.bashrc
        echo ${ptest} >> ~/.bashrc
        . ~/.bashrc
    fi

elif [ -f ~/.bash_profile ]; then
    if ! grep -q "prun" ~/.bash_profile; then
        echo ${prun} >> ~/.bash_profile
        echo ${ptest} >> ~/.bash_profile
        . ~/.bash_profile
    fi
fi

chmod +x ./scripts/bash/mf.sh
./scripts/bash/mf.sh ${projectname}

#run build
cmake .
make