from math import *
from queue import Queue
import json
import requests

host = "http://202.38.93.241:10024"


ln = lambda x: log(x, exp(1))
sqr = lambda x: x ** 2
funcs = [sin, cos, tan, asin, acos, atan, sinh, cosh, tanh, asinh, acosh, atanh, exp, ln, sqr, lambda x: -x,
         lambda x: 1 / x, radians, degrees]
names = ['sin', 'cos', 'tan', 'asin', 'acos', 'atan', 'sinh', 'cosh', 'tanh', 'asinh', 'acosh', 'atanh', 'exp', 'log',
         'x^2', '-x', '1/x', 'D2R', 'R2D']
l = [(0,[-1])]

class Processor():
    def __init__(self):
        self.sess = requests.session()
        r = self.sess.get(host + '/challenges')
        self.X = json.loads(r.text)["msg"]
        self.ans = [None, None, None]
        self.done = False
        print(self.X)

    def update(self, value, opt):
        for i in range(3):
            if fabs(value - self.X[i]) > 1e-5:
                continue
            if self.ans[i] is None or fabs(value - self.X[i]) < fabs(self.ans[i][0] - self.X[i]):
                self.ans[i] = (value, opt)

    def fm(self, opt):
        return ','.join([names[idx] for idx in opt if idx != -1])

    def submit(self):
        if self.done:
            return False
        if self.ans[0] is None or self.ans[1] is None or self.ans[2] is None:
            return False

        data = {
            "a1": self.fm(self.ans[0][1]),
            "a2": self.fm(self.ans[1][1]),
            "a3": self.fm(self.ans[2][1])
        }

        r = self.sess.post(host + "/submit", data=data)
        resp = json.loads(r.text)
        print(resp["msg"])
        self.done = True

P = 3

if __name__ == "__main__":
    processor = [Processor() for i in range(P)]
    Undone = P

    showed = {0}
    q = Queue()
    q.put((0,[-1]))
    while Undone > 0:
        x, op = q.get()
        for idx, func in enumerate(funcs):
            try:
                res = func(x)
            except:
                continue
            if isnan(res) or fabs(res) < 0.01 or fabs(res) > 100 or res in showed:
                continue
            showed.add(res)
            opt = op + [idx]
            q.put((res, opt))
            for p in processor:
                p.update(res, opt)
        for p in processor:
            if p.submit():
                print("Congratulations!")
