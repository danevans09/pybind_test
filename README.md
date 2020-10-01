# pybind_test

pybind_test is an example repo to set up and use pybind11 to interface Python and C++.

test_cpp.cc contains the C++ code, test_py.py contains the Python code, and CMakeLists.txt contains build information

Please see https://pybind11.readthedocs.io/en/stable/ for detailed information

## Installation and Compilation

You will need to create a build directory and move test_py.py into the build directory.

After cloning this repository:
```bash
cd pybind_test
mkdir build
cd build
cmake ..
mv ../test_py.py ./
make -j4
python test_py.py
```

## Usage

```python
import pybind_test

pbt = pybind_test([0.0, 0.1, 0.3, 0.4], {1: 0.0, 2: 0.1, 3: 0.3, 4: 0.4})
print(pbt.return_list())

pbt.erase(1.0)
print(pbt.return_list())
```
