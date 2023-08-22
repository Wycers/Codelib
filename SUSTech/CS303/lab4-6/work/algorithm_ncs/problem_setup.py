import pickle
import numpy as np
from algorithm_ncs import *

def save_parameter(para, file_name):
    with open(file_name, 'wb') as file_saver:
        data = pickle.dumps(para)
        file_saver.write(data)


def load_parameter(file_name) :
    with open(file_name, 'rb') as file:
        para = pickle.loads(file.read())
    if para is emptyPara:
        raise ValueError("not parameter type")
    return para


def load_problem6():
    (o, A, M, a, alpha, b, lu) = [None] * 7
    problem6_opti = "../datasets_ncs/rosenbrock_func_data.txt"
    with open(problem6_opti, 'r') as f:
        data = f.readlines()[0].split(" ")
        optimal = []
        i = 0
        for d in data:
            if d != "":
                optimal.append(float(d))
                i += 1
        o = np.asarray(optimal)
    lu = [-100, 100]
    return Parameter(o, A, M, a, alpha, b, lu)

def load_problem8():
    (o, A, M, a, alpha, b, lu) = [None] * 7
    problem6_opti = "../datasets_ncs/ackley_func_data.txt"
    with open(problem6_opti, 'r') as f:
        data = f.readlines()[0].split(" ")
        optimal = []
        i = 0
        for d in data:
            if d != "":
                optimal.append(float(d))
                i += 1
        o = np.asarray(optimal)
    ackley_M_D30 = "../datasets_ncs/ackley_M_D30.txt"
    with open(ackley_M_D30, 'r') as f:
        lines_data = f.readlines()
        lines = []
        for data in lines_data:
            line = []
            for d in data.split(" "):
                if d != "":
                    line.append(float(d))
            lines.append(line)
    M = np.array(lines)
    lu = [-32, 32]
    return Parameter(o, A, M, a, alpha, b, lu)


def load_problem9():
    (o, A, M, a, alpha, b, lu) = [None] * 7
    problem6_opti = "../datasets_ncs/rastrigin_func_data.txt"
    with open(problem6_opti, 'r') as f:
        data = f.readlines()[0].split(" ")
        optimal = []
        i = 0
        for d in data:
            if d != "":
                optimal.append(float(d))
                i += 1
        o = np.asarray(optimal)
    lu = [-5, 5]
    return Parameter(o, A, M, a, alpha, b, lu)


def load_problem10():
    (o, A, M, a, alpha, b, lu) = [None] * 7
    problem6_opti = "../datasets_ncs/rastrigin_func_data.txt"
    with open(problem6_opti, 'r') as f:
        data = f.readlines()[0].split(" ")
        optimal = []
        i = 0
        for d in data:
            if d != "":
                optimal.append(float(d))
                i += 1
        o = np.asarray(optimal)
    ackley_M_D30 = "../datasets_ncs/rastrigin_M_D50.txt"
    with open(ackley_M_D30, 'r') as f:
        lines_data = f.readlines()
        lines = []
        for data in lines_data:
            line = []
            for d in data.split(" "):
                if d != "":
                    line.append(float(d))
            lines.append(line)
    M = np.array(lines)
    lu = [-5, 5]
    return Parameter(o, A, M, a, alpha, b, lu)



def load_problem12():
    (o, A, M, a, alpha, b, lu) = [None] * 7
    problem6_opti = "../datasets_ncs/schwefel_213_data.txt"
    with open(problem6_opti, 'r') as f:
        lines_data = f.readlines()
        lines = []
        for data in lines_data:
            line = []
            for d in data.split(" "):
                if d != "":
                    line.append(float(d))
            lines.append(line)
    a = np.asarray(lines[0:100])
    b = np.asarray(lines[100:200])
    alpha = np.asarray(lines[-1])
    lu = [-np.math.pi, np.math.pi]
    return Parameter(o, A, M, a, alpha, b, lu)


emptyPara = Parameter(*[None] * 7)
problem_list = [lambda: emptyPara] * 30
problem_list[6] = load_problem6
problem_list[8] = load_problem8
problem_list[9] = load_problem9
problem_list[10] = load_problem10
problem_list[12] = load_problem12


if __name__ == '__main__':
    problem_set = [6, 8, 9, 10, 12]
    for p in problem_set:
        print("\n************the problem %d setup started!************" % p)
        para = problem_list[p]()
        if para != emptyPara:
            save_path = "../datasets_ncs/format/function%d.rw" % p
            save_parameter(para, save_path)
            newp = load_parameter(save_path)
            print("success")
        else:
            print("is None")
