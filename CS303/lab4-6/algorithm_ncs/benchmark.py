import numpy as np


def benchmark_func(x, problem, parameter):
    """
    :type problem: int
    """
    if problem < 0 or problem >= len(func_list):
        raise ValueError("none exist problem")
    o = parameter.o
    A = parameter.A
    M = parameter.M
    a = parameter.a
    alpha = parameter.alpha
    b = parameter.b
    return func_list[problem](x, o, A, M, a, alpha, b)


class BaseFunc:

    def func(self, x, o, A, M, a, alpha, b):
        """
        :param x: the solution that to be judged
        :param o: the optimal solution
        :param A:
        :param M:
        :param a:
        :param alpha:
        :param b: f_bias
        :return:
        """
        raise NotImplementedError("implement me")

    def __call__(self, x, o, A, M, a, alpha, b):
        return self.func(x, o, A, M, a, alpha, b)


class Func6(BaseFunc):
    def func(self, x, o, A, M, a, alpha, b):
        num_col, dimension = x.shape
        fitness = np.zeros(num_col)
        for i in range(num_col):
            onefitness = 390
            z = x[i] - o + 1
            for d in range(dimension - 1):
                onefitness += 100 * (z[d] ** 2 - z[d + 1]) ** 2 + (z[d] - 1) ** 2
            fitness[i] = onefitness
        return fitness


class Func8(BaseFunc):
    def func(self, x, o, A, M, a, alpha, b):
        num_col, dimension = x.shape
        fitness = np.zeros(num_col)
        for i in range(num_col):
            onefitness = 390
            z = x[i] - o + 1
            for d in range(dimension - 1):
                onefitness += 100 * (z[d] ** 2 - z[d + 1]) ** 2 + (z[d] - 1) ** 2
            fitness[i] = onefitness
        return fitness


class Func9(BaseFunc):
    def func(self, x, o, A, M, a, alpha, b):
        num_col, dimension = x.shape
        fitness = np.full(num_col, -330.)
        z = x - np.tile(o, (num_col, 1))
        fitness += np.sum(z**2 - 10*np.cos(2*np.pi*z), 1) + 10 * dimension
        return fitness

class Func10(BaseFunc):
    def func(self, x, o, A, M, a, alpha, b):
        num_col, dimension = x.shape
        fitness = np.full(num_col, -330.)
        z = np.dot(x - np.tile(o, (num_col, 1)), M)
        fitness += np.sum(z**2 - 10*np.cos(2*np.pi*z), 1) + 10 * dimension
        return fitness



class Func12(BaseFunc):
    def __init__(self):
        self.A = None
        self.is_init = False

    def func(self, x, o, A, M, a, alpha, b):
        num_col, dimension,  = x.shape
        fitness = np.zeros(num_col)
        if not self.is_init:
            self.A = np.dot(a, np.sin(alpha)) + np.dot(b, np.cos(alpha))
            # for i in range(dimension):
            #     # calculate Ai and Bi
            #     self.A[i] = np.dot(a[i], np.sin(alpha)) + np.dot(b[i], np.cos((alpha)))
            #     for j in range(dimension):
            #         self.A[i] += a[i][j] * np.sin(alpha[j]) + b[i][j] * np.cos(alpha[j])
            self.is_init = True

        for n in range(num_col):
            onefitness = -460

            onefitness += sum((np.dot(a, np.sin(x[n])) + np.dot(b, np.cos(x[n])) - self.A)**2)
            # for i in range(dimension):
            #     # calculate Ai and Bi
            #     Ai = self.A[i]
            #     Bi = np.dot(a[i], np.sin(x[n])) + np.dot(b[i], np.cos(x[n]))
            #     # for j in range(dimension):
            #     #     Bi += b[i][j]*np.cos(x[j][n])
            #     onefitness += (Ai-Bi) ** 2
            fitness[n] = onefitness
        return fitness


func_list = [BaseFunc()] * 30
func_list[6] = Func6()
func_list[9] = Func9()
func_list[10] = Func10()
func_list[12] = Func12()
