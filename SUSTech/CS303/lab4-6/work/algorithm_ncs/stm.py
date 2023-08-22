import json

from algorithm_ncs import ncs_c as ncs
import argparse
import random

parser = argparse.ArgumentParser(description="This is a NCS solver")
parser.add_argument("-c", "--config", default="algorithm_ncs/parameter.json",
                    type=str, help="a json file that contains parameter")
parser.add_argument("-d", "--data", default="6", type=int,
                    help="the problem dataset that need to be solved")
args = parser.parse_args()


"""
how to use it?
example:
    python3 -m algorithm_ncs.ncs_client -d 12 -c algorithm_ncs/parameter.json

good luck!
"""
if __name__ == '__main__':
    config_file = args.config
    p = args.data
    with open(config_file) as file:
        try:
            ncs_para = json.loads(file.read())
        except:
            raise Exception("not a json format file")
    res = 100000000
    while True:
        r = random.uniform(0.6, 1)
        _lambda = random.uniform(0.5, 1)
        epoch = random.randint(1, 50)
        n = 1
        ncs_para = ncs.NCS_CParameter(
            tmax=300000, lambda_exp=_lambda, r=r, epoch=epoch, N=n)
        print("************ start problem %d **********" % p)
        ncs_c = ncs.NCS_C(ncs_para, p)
        ncs_res = ncs_c.loop(quiet=True, seeds=0)
        print(ncs_res)
        if  ncs_res < res:
            res = ncs_res
            f = open('nmd', 'a')
            f.write('{}, {}, {}, {}\n'.format(_lambda, r, epoch, n))
            f.close()
            print(_lambda, r, epoch, n)
