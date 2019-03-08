import n, n2, n3, nf, nlogn
import time


def cal(i, f):
    start = time.process_time()
    f(i)
    end = time.process_time()
    return end - start

for i in [3 ** i for i in range(0, 8)]:
    for work in [n.work, n2.work, n3.work, nf.work, nlogn.work]:
        print(cal(i, work))
    print()