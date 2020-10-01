cmake_minimum_required(VERSION 2.8.12)
project(pybind_test)


include(FetchContent ${PYTHON_INCLUDE_PATH})
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11
    GIT_TAG        v2.2.3
)

FetchContent_GetProperties(pybind11)
if(NOT pybind11_POPULATED)
    FetchContent_Populate(pybind11)
    add_subdirectory(${pybind11_SOURCE_DIR} ${pybind11_BINARY_DIR})
endif()

pybind11_add_module(pybind_test test_cpp.cc)
target_link_libraries(pybind_test PRIVATE ${MY_LIBRARIES})