import numpy as np
import unittest
from algorithm_ncs.benchmark import benchmark_func
from algorithm_ncs.problem import load_problem


def load_test_data(file_path):
    with open(file_path, "r") as f:
        lines_data = f.readlines()
        lines = []
        for data in lines_data:
            line = []
            for d in data.split(" "):
                if d != "":
                    line.append(float(d))
            lines.append(line)
    x = np.asarray(lines[0:10])
    v = np.asarray(lines[10:]).reshape(10)
    return x, v


def test_func(problem_index):
    file_path = "datasets_ncs/test_data_func{}.txt".format(problem_index)
    x, v = load_test_data(file_path)
    para = load_problem(problem_index, 50)
    res = benchmark_func(x, problem_index, para)
    return v, res


class FuncTest(unittest.TestCase):

    def setUp(self) -> None:
        pass

    def tearDown(self) -> None:
        pass

    def test_fun6(self):
        v, res = test_func(6)
        for i in range(len(res)):
            self.assertTrue(abs((v[i]-res[i])/v[i]) < 0.001)

    def test_fun12(self):
        v, res = test_func(12)
        for i in range(len(res)):
            self.assertTrue(abs((v[i]-res[i])/v[i]) < 0.001)


    def test_fun9(self):
        v, res = test_func(9)
        for i in range(len(res)):
            self.assertTrue(abs((v[i]-res[i])/v[i]) < 0.001)


    def test_fun10(self):
        v, res = test_func(10)
        for i in range(len(res)):
            self.assertTrue(abs((v[i]-res[i])/v[i]) < 0.001)



if __name__ == '__main__':
    unittest.main()


