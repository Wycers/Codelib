import n, n2, n3, nf, nlogn, pown
import time, dis


def cal(i, f):
    start = time.process_time()
    f(i)
    end = time.process_time()
    return end - start

cases = [3 ** i for i in range(0, 8)]
f = open('res.csv', 'w')
f.write('complexity')
for i in cases:
    f.write(', n = %d' % i)
f.write('\n')

for now in [n, nlogn, n2, n3, nf]:
    f.write('O(%s)' % now.__name__)
    for i in cases:
        f.write(', %f' % cal(i, now.work))
    f.write('\n')
close(f)