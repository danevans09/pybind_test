import pybind_test
import numpy as np

np.random.seed(0)

test_list = list(np.random.rand(10))
test_dict = {i: test_list[i] for i in range(len(test_list))}

print(test_list)
pb_test = pybind_test.Test(test_list, test_dict)
print(pb_test.return_list())

pb_test.erase(0.01)
print(pb_test.return_list())

pb_test.erase(0.99)
print(pb_test.return_list())
