from queue import Queue
import multiprocessing as mp
import time
import sys
import argparse
import os
import random
import numpy as np

worker_num = 8
epoch = 2000


class Node:
    def __init__(self, name, threshold=None):
        self.name = name
        self.next = []
        self.weight = []


class Worker(mp.Process):
    def __init__(self):
        super(Worker, self).__init__(target=self.start)
        self.inQ = mp.Queue()
        self.outQ = mp.Queue()

    def run(self):
        while True:
            model, nodes, seeds = self.inQ.get()
            if model == 'IC':
                self.outQ.put(IC(nodes, seeds))
            elif model == 'LT':
                self.outQ.put(LT(nodes, seeds))


def IC(nodes, seeds):
    random.seed(int(os.getpid() + time.time() * 1e3 + 114514))

    cnt = 0
    queue = []
    acted = [0]* len(nodes)

    for i in seeds:
        queue.append(i)
        acted[i.name] = 1
        cnt = cnt + 1

    while(len(queue) != 0):
        for i in range(len(queue[0].next)) :
            if acted[queue[0].next[i].name] == 0 :
                ret = random.random()
                if ret <= queue[0].weight[i] :
                    cnt = cnt + 1
                    acted[queue[0].next[i].name]  = 1
                    queue.append(queue[0].next[i])

        del queue[0]
    return sum([1 for node in nodes if acted[node.name]])


def LT(nodes, seeds):
    random.seed(int(os.getpid() + time.time() * 1e3 + 114514))

    queue = [[], []]
    now = 0

    acted = [False] * len(nodes)
    threshold = [random.random() for _ in nodes]

    for i in seeds:
        queue[now].append(i)

    while len(queue[now]) > 0:
        for u in queue[now]:
            acted[u.name] = True
            for i in range(len(u.next)):
                threshold[u.next[i].name] -= u.weight[i]

        for u in queue[now]:
            for i in range(len(u.next)):
                if acted[u.next[i].name]:
                    continue
                if threshold[u.next[i].name] > 0:
                    continue
                queue[now ^ 1].append(u.next[i])
                acted[u.next[i].name] = True
        queue[now] = []
        now ^= 1

    return sum([1 for node in nodes if acted[node.name]])


if __name__ == '__main__':
    start = time.time()

    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--file_name', type=str, default='network.txt')
    parser.add_argument('-s', '--seed', type=str, default='seed1.txt')
    parser.add_argument('-m', '--model', type=str, default='IC')
    parser.add_argument('-t', '--time_limit', type=int, default=120)

    args = parser.parse_args()
    time_limit = args.time_limit

    nodes = []
    with open(args.file_name) as f:
        line = f.readline()
        tmp = line.split(' ')
        N = int(tmp[0])
        for i in range(N+1):
            nodes.append(Node(int(i)))

        for line in f:
            tmp = line.split(' ')

            l = int(tmp[0].strip())
            r = int(tmp[1].strip())
            w = float(tmp[2].strip())
            nodes[l].next.append(nodes[r])
            nodes[l].weight.append(w)

    seeds = []
    with open(args.seed) as f:
        for line in f:
            tmp = int(line.strip())
            seeds.append(nodes[tmp])

    sys.setrecursionlimit(1000000)

    if worker_num == 0 or epoch == 0:
        exit(0)

    random.seed(int(os.getpid() + time.time() * 1e3 + 114514))

    workers = []
    for i in range(worker_num):
        workers.append(Worker())
        workers[i].start()

    data = (args.model, nodes, seeds)
    for i in range(epoch):
        workers[i % worker_num].inQ.put(data)

    totalsum = 0
    for i in range(epoch):
        totalsum += workers[i % worker_num].outQ.get()

    print(totalsum/epoch)
    # print(time.time() - start)

    for w in workers:
        w.terminate()


    sys.stdout.flush()

