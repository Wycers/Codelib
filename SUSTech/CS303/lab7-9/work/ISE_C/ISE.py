# -*- coding: utf-8 -*-
# written by mark zeng 2018-11-14
# modified by Yao Zhao 2019-10-30

from multiprocessing import Pool
import time
import sys
import argparse
import os
import random
import numpy as np
import copy
import ctypes

worker_num = 8
start = time.time()

def IC_model(time_budget):
    model_start = time.time()

    global network, seed
    nmd = ctypes.cdll.LoadLibrary('./ic.so')
    c_network = ctypes.c_char_p(network)
    c_seed = ctypes.c_char_p(seed)
    nmd.init(c_network, c_seed)

    res, cnt = 0, 0
    while time.time() - model_start < time_budget - 3:
        seed = int(os.getpid() + time.time() * 1e3 + random.randint(0, 114514)) & 0x0FFFFFFF
        res += nmd.IC(ctypes.c_int(seed))
        cnt += 1
    return res, cnt

def LT_model(time_budget):
    model_start = time.time()

    global network, seed
    nmd = ctypes.cdll.LoadLibrary('./lt.so')
    c_network = ctypes.c_char_p(network)
    c_seed = ctypes.c_char_p(seed)
    nmd.init(c_network, c_seed)

    res, cnt = 0, 0
    while time.time() - model_start < time_budget - 3:
        seed = int(os.getpid() + time.time() * 1e3 + random.randint(0, 114514)) & 0x0FFFFFFF
        res += nmd.LT(ctypes.c_int(seed))
        cnt += 1
    return res, cnt


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--file_name', type=str, default='network.txt')
    parser.add_argument('-s', '--seed', type=str, default='seed1.txt')
    parser.add_argument('-m', '--model', type=str, default='IC')
    parser.add_argument('-t', '--time_limit', type=int, default=120)

    args = parser.parse_args()
    network = args.file_name.encode()
    seed = args.seed.encode()
    model = args.model
    time_limit = args.time_limit

    with Pool(worker_num) as p:
        if model == 'IC':
            res = p.map(IC_model, [(time_limit - (time.time() - start)) for i in range(worker_num)])
        elif model == 'LT':
            res = p.map(LT_model, [(time_limit - (time.time() - start)) for i in range(worker_num)])
        total_sum = 0
        cnt = 0
        for r, c in res:
            total_sum += r
            cnt += c
        print(total_sum / cnt)
    sys.stdout.flush()
