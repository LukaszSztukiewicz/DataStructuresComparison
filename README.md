#CuPyterLab

Environment for performing experminents in C++ and data analisys in Python with extensive support for Jupyter Notebooks.

Target Operating Systems: Linux / WSL2

Style Guide
[Google Style Guide](https://google.github.io/styleguide/cppguide.html)

File extensions:
 - .cc for C++ (Linux style)
 - .h for C++ headers

Setup: Linux
chmod +x ./scripts/bash/cpp-env-setup.sh
./scripts/bash/cpp-env-setup.sh

For Debug:
cmake . -DCMAKE_BUILD_TYPE=Debug

Build: make

Run: prun

Test: ptest

Dependencies:
+google test
+cmake
-btaf
-graphviz, anim