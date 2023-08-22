from multiprocessing import Pool
from algorithm_ncs import ncs_c as ncs
from math import exp
import numpy as np
import json, os, time
p = 6


class Parameter():
    def __init__(self, r, l, e, n, val=None):
        self.r = r
        self.l = l
        self.e = e
        self.n = n
        self._val = val

    @classmethod
    def fromJson(self):
        with open('%d.json' % p, 'r') as f:
            data = json.load(f)
            if 'val' in data:
                return Parameter(data['r'], data['lambda'], data['epoch'], data['n'], data['val'])
            else:
                return Parameter(data['r'], data['lambda'], data['epoch'], data['n'])

    def check(self):
        if self.r < 0.25 or self.r > 1.25:
            return False
        if self.l < 0.25 or self.l > 1.25:
            return False
        if self.e < 1 or self.e > 150:
            return False
        if self.n < 1 or self.n > 4:
            return False
        return True

    def __str__(self):
        return "r: {}, lambda: {}, epoch: {}, n: {}, val: {}".format(self.r, self.l, self.e, self.n, self._val)

    def saveJson(self):
        with open('%d.json' % p, 'w') as f:
            data = {
                'r': self.r,
                'lambda': self.l,
                'epoch': self.e,
                'n': self.n,
                'val': self._val
            }
            json.dump(data, f)

    def run(self, quiet=False):
        ncs_para = ncs.NCS_CParameter(
            tmax=300000, lambda_exp=self.l, r=self.r, epoch=self.e, N=self.n)
        print(self)
        ncs_c = ncs.NCS_C(ncs_para, p)
        ncs_res = ncs_c.loop(quiet=quiet, seeds=0)
        print(ncs_res)
        self._val = ncs_res

    @property
    def val(self):
        if self._val is None:
            self.run(True)
        return self._val


def sa():
    T = 1000  # initiate temperature
    Tmin = 10  # minimum value of terperature

    param = Parameter.fromJson()

    k = 50   # times of internal circulation
    res = 0  # initiate result
    t = 0    # time
    while T >= Tmin:
        param.run(False)
        print(param.val)
        for i in range(k):
            # generate a new x in the neighboorhood of x by transform function
            new_param = Parameter(
                param.r +
                np.random.uniform(low=-0.0005, high=0.0005) * T,
                param.l +
                np.random.uniform(low=-0.0005, high=0.0005) * T,
                param.e, param.n
            )
            print(new_param)
            if new_param.check():
                new_param.run(True)
                if new_param.val < param.val:
                    print("Programly jump to", new_param)
                    print("New result:", new_param.val)
                    param = new_param
                else:
                    # metropolis principle
                    p = exp(-1e4 * (new_res.val - res.val) / T)
                    r = np.random.uniform(low=0, high=1)
                    if r > p:
                        print("Randomly jump to", new_param)
                        print("Probability", p)
                        param = new_param
        t += 1
        print(t)
        T = 1000 / (1+t)

    print(param.val)

def random():
    np.random.seed(int(os.getpid() + time.time() + 114514))
    param = Parameter(
        np.random.uniform(low=0.4, high=1.1),
        np.random.uniform(low=0.4, high=1.1),
        np.random.randint(10, 125),
        np.random.randint(1, 2),
    )
    # if not param.check():
    #     return
    best = Parameter.fromJson()
    if best.val > param.val:
        param.saveJson()


if __name__ == '__main__':
    with Pool(1) as p:
        for i in range(1):
            p.apply_async(random, args=())
        p.close()
        p.join()
