# CuPyterLab
Environment for performing experminents in C++ and data analisys in Python with extensive support for Jupyter Notebooks.

[Google Style Guide](https://google.github.io/styleguide/cppguide.html)

Target: 

 - [x] Linux
 - [x] WSL2

### Setup: 
#### Linux

    $ chmod +x ./scripts/bash/cpp-env-setup.sh && $_

### Usage
Build: 

    $ make

Run: 

    $ prun

Test: 

    $ ptest

Debug:

    $ cmake . -DCMAKE_BUILD_TYPE=Debug

### Dependencies:
 - [x] google test
 - [x] cmake
 - [ ] btaf
 - [ ] graphviz, anim
 - [ ] gdb

File extensions:
 - .cc for C++ (Linux style)
 - .h for C++ headers
