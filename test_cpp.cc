#include <pybind11/pybind11.h>
#include <cstdlib> 
#include <iostream>
#include <string>
#include <random>
#include "RandomNumbers.h"

namespace py = pybind11;


// A struct in C++ is similar to a Python class that only holds properties/attributes
struct cpp_dict_entry
    {
    std::string name;
    float val;
    }


// C++ classes are similar in structure to Python classes
class Test
    {
    // "public" means this code can be accessed outside of this file
    public:
        // This is essentially the __init__ method of python classes
        Test(py::list l, py::dict d)
            {
            float [l.size()] l_array; // arrays are the best substiture for python lists / numpy arrays
            for (int i = 0; i < l.size(); l++)
                {
                float cpp_float_li = static_cast<float>(l[i]); // Python floats must be "cast" to C++ floats
                l_vector.push_back(cpp_float_li); // l_vector is a "member" variable. push_back is analagous to Python list.append
                l_array[i] = cpp_float_li; // arrays are static length so you set each element
                }

            std::vector<cpp_dict_entry> d_cpp; // vectors are dynamic arrays - slower but more flexible
            for (auto item : d)
                {
                // Dictionary values can be accessed this way
                cpp_dict_entry entry;
                entry.name = item.first; // key
                entry.val = item.second; // val
                d_cpp.push_back(entry);
                }
            }


        void erase_from_vec(float erase)
            {
            // Random number generatir for [0, 1]
            std::default_random_engine generator;
            std::uniform_real_distribution<float> distribution(0.0, 1.0);

            // If random number < erase probability
            if (distribution(generator) < erase)
                {
                // Find random integer within the size of l_vector
                std::random_device rd;
                std::mt19937 rng(rd());
                std::uniform_int_distribution<int> uni(0, l_vector.size());
                auto random_integer = uni(rng);

                // Remove the vector element corresponding to the index random_integer
                l_vector.erase(l_vector.begin()+random_integer);
                }
            }

        // Return the results of the analysis back to Python
        py::list return_list()
            {
            py::list l_py;
            for (int i = 0; i < l_vector.size(); l++)
                {
                l_py.append(l_vector[i]);
                }
            return l_py
            }

    private:
        // These are member variables, similar to properties or attributes in Python
        // "private" means these variables can only be accessed within this class
        std::vector<float> l_vector;
    }


PYBIND11_MODULE(pybind_test, m)
    {
        py::class_<Test>(m, "Test")
            .def(py::init<py::list, py::dict>())
            .def("erase", &Influence::erase_from_vec)
            .def("return_list", &Influence::return_list);
    }
