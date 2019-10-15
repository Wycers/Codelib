from algorithm_ncs import ncs_c as ncs
from math import exp
import numpy as np


class Parameter():
    def __init__(self, r, l, e, n):
        self.r = r
        self.l = l
        self.e = e
        self.n = n

    def check(self):
        if r < 0 or r > 100:
            return False
        if l < 0 or l > 100:
            return False
        if e < 0 or e > 100:
            return False
        if n < 0 or n > 100:
            return False
        return True

    def __str__(self):
        return "r: {}, lambda: {}, epoch: {}, n: {}".format(self.r, self.l, self.e, self.n)


def run(parameter, quiet=False):
    p = 6
    ncs_para = ncs.NCS_CParameter(
        tmax=300000, lambda_exp=parameter.l, r=parameter.r, epoch=parameter.e, N=parameter.n)
    print("************ start problem %d **********" % p)
    print(parameter)
    ncs_c = ncs.NCS_C(ncs_para, p)
    ncs_res = ncs_c.loop(quiet=quiet, seeds=0)
    print(ncs_res)
    return ncs_res


if __name__ == '__main__':
    T = 1000  # initiate temperature
    Tmin = 10  # minimum value of terperature

    param = Parameter(
        np.random.uniform(low=0, high=10),
        np.random.uniform(low=0, high=1),
        np.random.randint(1, 50),
        np.random.randint(1, 4)
    )

    print(run(param))

    k = 50  # times of internal circulation
    res = 0  # initiate result
    t = 0  # time
    while T >= Tmin:
        for i in range(k):
            res = run(param)
            # generate a new x in the neighboorhood of x by transform function
            new_param = Parameter(
                param.r + np.random.uniform(low=-0.055, high=0.055) * T,
                param.l + np.random.uniform(low=-0.055, high=0.055) * T,
            )
            if new_param.check():
                new_res = run(new_param)
                if new_res < res:
                    param = new_param
                else:
                    # metropolis principle
                    p = exp(-(new_res - res) / T)
                    r = np.random.uniform(low=0, high=1)
                    if r < p:
                        param = new_param
        t += 1
        print(t)
        T = 1000 / (1+t)

    print(run(param))
