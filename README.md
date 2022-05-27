# DataStructuresComparison

Code of experiments on data structures done in the CuPyterLab environment

Test with Valgrind
```
    valgrind --leak-check=full ./bin/DataStructuresComparison_test
```
```
    valgrind --leak-check=full ./bin/DataStructuresComparison_run
```

[Google Style Guide](https://google.github.io/styleguide/cppguide.html)

### Usage
First build:
```
    cmake . 
```
Build: 
```
    make
```
Run: 
```
    ./bin/DataStructuresComparison_run
```
Test: 
```
    ./bin/DataStructuresComparison_test
```
Debug:
```
    cmake . -DCMAKE_BUILD_TYPE=Debug
```

### Dependencies:
 - [x] google test
 - [x] cmake
 - [x] Valgrind

File extensions:
 - .cc for C++ (Linux style)
 - .h for C++ headers
