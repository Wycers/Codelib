import argparse
import sys
import numpy as np
import math
import time


class Graph:
    def __init__(self, n):
        self.n = n

        self.to = []
        self.next = []
        self.w = []

        self.head = [0] * n

    def add(self, u, v, w):
        self.to.append(v)
        self.next.append(self.head[u])
        self.w.append(w)

        self.head[u] = len(self.next) - 1

    def go_from(self, u):
        now = self.head[u]
        while now != 0:
            yield self.to[now], self.w[now]
            now = self.next[now]


class reverse_reachable_set_collection:
    def __init__(self, rev_graph):
        self.sets = []
        self.rev_graph = rev_graph

    def generate(self, node):
        queue = [node]
        res = set()
        while len(queue) != 0:
            u = queue[0]
            for v, w in self.rev_graph.go_from(u):
                if v in res:
                    continue
                if np.random.rand() < w:
                    res.add(v)
                    queue.append(v)
            del queue[0]
        self.sets.append(res)

    def expand(self, upper_bound):
        while len(self.sets) <= upper_bound:
            self.generate(np.random.randint(0, N - 1))

    def node_selection(self, k):
        res = set()
        rd = {}  # rd[i] 表示 i出现过的反向可达图的标号
        count = [0] * N  # count[i] 表示 i在所有反向可达图中出现的次数

        for i in range(0, len(self.sets)):
            for j in self.sets[i]:
                count[j] += 1
                if j in rd:
                    rd[j].append(i)
                else:
                    rd[j] = [i]

        coverd = set()
        while len(res) < k:
            s = count.index(max(count))
            res.add(s)
            rr = rd[s].copy()
            for i in rr:
                coverd.add(i)
                for j in self.sets[i]:
                    rd[j].remove(i)
                    count[j] -= 1

        return res, len(coverd) / len(self.sets)


def log_n_k(n, k):
    return sum([math.log(x) for x in range(n - k + 1, n + 1)]) - sum([math.log(x) for x in range(1, k + 1)])


if __name__ == '__main__':
    start = time.time()
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", type=argparse.FileType('r'), default=sys.stdin)
    parser.add_argument("-k", type=int)
    parser.add_argument("-m", type=str)
    parser.add_argument("-t", type=int)
    args = parser.parse_args()

    tmp = args.i.readline().strip().split(" ")
    # read edges and nodes
    N = int(tmp[0])
    M = int(tmp[1])

    rrsc = reverse_reachable_set_collection(Graph(N))

    # read edge
    for i in range(M):
        source, dest, weight = args.i.readline().strip().split(" ")
        source = int(source) - 1
        dest = int(dest) - 1
        weight = float(weight)

        rrsc.rev_graph.add(dest, source, weight)


    k = args.k
    e = 0.1
    l = (1 + math.log(2) / math.log(N))
    e_dot = math.sqrt(2) * e
    init = time.time()
    last = time.time()
    for i in range(1, int(math.log(N, 2))):
        t0 = time.time()
        x = N / math.pow(2, i)
        lambda_dot = (2 + 2 / 3 * e_dot) * (
                log_n_k(N, k) + l * math.log(N) + math.log(math.log(N, 2))) * N / math.pow(e_dot, 2)
        theta_i = lambda_dot / x

        rrsc.expand(theta_i)

        seeds, fr = rrsc.node_selection(args.k)
        print(seeds)
        if N * fr >= (1 + e_dot) * x:
            break
        if time.time() - start + time.time() - t0 >= args.t - 3:
            break

    for seed in seeds:
        print(seed + 1)
