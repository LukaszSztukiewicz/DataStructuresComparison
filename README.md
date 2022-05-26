# DataStructuresComparison

Code of experiments on data structures done in the CuPyterLab environment

Test with Valgrind
valgrind --leak-check=full ./bin/DataStructuresComparison_test
valgrind --leak-check=full ./bin/DataStructuresComparison_run

or use built-in ctest:
ctest -T memcheck

[Google Style Guide](https://google.github.io/styleguide/cppguide.html)

### Usage
Build: 
```
    make
```
Run: 
```
    prun
```
Test: 
```
    ptest
```
Debug:
```
    cmake . -DCMAKE_BUILD_TYPE=Debug
```
easiest with 
### Dependencies:
 - [x] google test
 - [x] cmake
 - [x] Valgrind

File extensions:
 - .cc for C++ (Linux style)
 - .h for C++ headers
