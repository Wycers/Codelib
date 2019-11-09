# -*- coding: utf-8 -*-
# written by mark zeng 2018-11-14
# modified by Yao Zhao 2019-10-30

import multiprocessing as mp
import time
import sys
import argparse
import os
import random
import numpy as np
import copy
import ctypes

worker_num = 8
epoch = 1900000

def IC():
    a = nmd.IC()
    # print(a)
    return a

def LT():
    return 0

class Worker(mp.Process):
    def __init__ (self):
        super(Worker, self).__init__(target=self.start)
        self.inQ = mp.Queue()
        self.outQ = mp.Queue()

    def run (self):
        while True:
            model = self.inQ.get()  # 取出任务， 如果队列为空， 这一步会阻塞直到队列有元素
            if model=='IC':
                self.outQ.put(IC())
            elif model=='LT':
                self.outQ.put(LT())


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--file_name', type=str, default='network.txt')
    parser.add_argument('-s', '--seed', type=str, default='seed1.txt')
    parser.add_argument('-m', '--model', type=str, default='IC')
    parser.add_argument('-t', '--time_limit', type=int, default=120)

    args = parser.parse_args()
    file_name = args.file_name
    seed = args.seed
    model = args.model
    time_limit = args.time_limit

    nmd = ctypes.cdll.LoadLibrary('./nmd.so')
    network = file_name.encode()
    c_network = ctypes.c_char_p(network)
    seed = seed.encode()
    c_seed = ctypes.c_char_p(seed)
    nmd.init(c_network, c_seed)

    sys.setrecursionlimit(1000000)

    worker = []
    for i in range(worker_num):
        worker.append(Worker())
        worker[i].start()

    for i in range(epoch):
        worker[i % worker_num].inQ.put(model)  # 根据编号取模， 将任务平均分配到子进程上
    totalsum=0
    for i in range(epoch):
        totalsum+=worker[i % worker_num].outQ.get() # 用同样的规则取回结果， 如果任务尚未完成，此处会阻塞等待子进程完成任务
    print(totalsum/epoch)


    for w in worker:
        w.terminate()

    sys.stdout.flush()
