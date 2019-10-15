import time
from collections import namedtuple

import numpy as np

import algorithm_ncs.problem as ncs_problem
import algorithm_ncs.benchmark as benchmark

NCS_CParameter = namedtuple(
    "NCS_CParameter", ["tmax", "lambda_exp", "r", "epoch", "N"])


class NCS_C(object):

    def __init__(self, para: NCS_CParameter, problem):
        self.Tmax = para.tmax
        self.r = para.r
        self.epoch = para.epoch
        self.N = para.N  # pop size
        self._lambda_exp = para.lambda_exp
        self.problem_index = problem
        self.Dimension = 30
        self.problem_para = ncs_problem.load_problem(problem, self.Dimension)
        self.result = 1e100

    def loop(self, quiet=False, seeds=None):
        if seeds is None:
            np.random.seed(int(100 * time.clock()))
        else:
            np.random.seed(seeds)
        # initial the main population
        p = np.tile(self.problem_para.lu[0, :], (self.N, 1)) + \
            np.random.random((self.N, self.Dimension)) * \
            np.tile(self.problem_para.lu[1, :] -
                    self.problem_para.lu[0, :], (self.N, 1))

        fit = benchmark.benchmark_func(
            p, self.problem_index, self.problem_para)
        min_fit = min(fit)
        sigma = np.tile(
            (self.problem_para.lu[1] - self.problem_para.lu[0]) / self.N, (self.N, 1))
        flag = np.zeros((self.N, 1))
        _lambda = np.full(self.N, self._lambda_exp, dtype=float)
        _lambda_sigma = 0.1
        _lambda_range = _lambda_sigma

        # Record the number of function evaluations(FES)
        FES = self.N
        Gen = 0

        # use to check the boundary constraints
        xl = np.tile(self.problem_para.lu[0], (self.N, 1))
        xu = np.tile(self.problem_para.lu[1], (self.N, 1))

        while FES < self.Tmax:
            # generate a set of new trial individuals
            uSet = p + sigma * np.random.normal(size=(self.N, self.Dimension))

            # let value of uSet less than xl to be 2*xl-uSet
            pos = uSet < xl
            uSet[pos] = 2. * xl[pos] - uSet[pos]
            pos_ = np.where(pos)
            for i in range(len(pos_[0])):
                if uSet[pos_[0][i]][pos_[1][i]] > xu[pos_[0][i]][pos_[1][i]]:
                    uSet[pos_[0][i]][pos_[1][i]] = xu[pos_[0][i]][pos_[1][i]]

            pos = uSet > xu
            uSet[pos] = 2. * xu[pos] - uSet[pos]
            pos_ = np.where(pos)
            for i in range(len(pos_[0])):
                if uSet[pos_[0][i]][pos_[1][i]] < xl[pos_[0][i]][pos_[1][i]]:
                    uSet[pos_[0][i]][pos_[1][i]] = xl[pos_[0][i]][pos_[1][i]]

            # Evaluate the trial vectors
            fitSet = benchmark.benchmark_func(
                uSet, self.problem_index, self.problem_para)
            FES = FES + self.N
            Gen = Gen + 1
            temp_min_f = min(fitSet.min(), min_fit)
            if temp_min_f != min_fit:
                min_fit = temp_min_f
                if not quiet:
                    print('the best result at the', Gen,
                          'th iteration is', min_fit)

            tempFit = fit - min_fit
            tempTrialFit = fitSet - min_fit
            normFit = tempFit / (tempFit + tempTrialFit)
            normTrialFit = tempTrialFit / (tempFit + tempTrialFit)

            # calculate the Bhattacharyya distance
            pCorr = np.full((self.N, self.N), 1e30, dtype=float)
            trialCorr = np.full((self.N, self.N), 1e30, dtype=float)

            for i in range(self.N):
                for j in range(self.N):
                    if j != i:
                        # BD between the ith parent and the other parents
                        m1 = p[i, :] - p[j, :]
                        c1 = (sigma[i, :] ** 2 + sigma[j, :] ** 2) / 2
                        # tempD = 0
                        # for k in range(self.Dimension):
                        #     tempD = tempD + np.log(c1[k]) - \
                        #             0.5 * (np.log(sigma[i][k] ** 2) + np.log(sigma[j][k] ** 2))

                        smart_tempD = np.log(c1).sum() - \
                            0.5 * (np.log(sigma[i] ** 2).sum() +
                                   np.log(sigma[j] ** 2).sum())
                        tempD = smart_tempD

                        pCorr[i, j] = np.dot(
                            1 / 8 * m1 / c1, m1) + 1 / 2 * tempD
                        # pCorr[i, j] = np.dot(np.dot(1 / 8 * m1, np.diag(1. / c1)), m1) + 1 / 2 * tempD
                        # BD between the ith offspring and the other parents
                        m2 = uSet[i, :] - p[j, :]
                        # trialCorr[i, j] = np.dot(np.dot(1 / 8 * m2, np.diag(1. / c1)), m2) + 1 / 2 * tempD
                        trialCorr[i, j] = np.dot(
                            1 / 8 * m2 / c1, m2) + 1 / 2 * tempD

            pMinCorr = np.min(pCorr, 1)
            trialMinCorr = np.min(trialCorr, 1)

            #  normalize correlation values
            normCorr = pMinCorr / (pMinCorr + trialMinCorr)
            normTrialCorr = trialMinCorr / (pMinCorr + trialMinCorr)
            _lambda = self._lambda_exp + _lambda_sigma * \
                np.random.normal(size=(self.N))
            _lambda_sigma = _lambda_range - \
                _lambda_range * Gen / (self.Tmax / self.N)
            pos = (_lambda * normTrialCorr > normTrialFit)
            p[pos, :] = uSet[pos, :]
            fit[pos] = fitSet[pos]
            flag[pos] = flag[pos] + 1

            # i/5 successful rule
            if Gen % self.epoch == 0:
                for i in range(self.N):
                    if flag[i] / self.epoch > 0.2:
                        sigma[i, :] = sigma[i, :] / self.r
                    elif flag[i] / self.epoch < 0.2:
                        sigma[i, :] = sigma[i, :] * self.r
                flag = np.zeros((self.N, 1))

        self.result = min_fit
        return min_fit

    def get_result(self):
        return self.result


if __name__ == '__main__':
    problem_set = [6, ]
    for p in problem_set:
        print("\n************ the problem %d started! ************\n" % p)
        start = time.time()
        ncs_para = NCS_CParameter(
            tmax=300000, lambda_exp=1, r=0.99, epoch=10, N=10)
        rep = 25
        fits = np.zeros(rep)
        ncs_c = NCS_C(ncs_para, p)
        for t in range(rep):
            fits[t] = ncs_c.loop(quiet=True)
            print('the {} time the {} th problem result is: {}'.format(
                t+1, p, ncs_c.get_result()))
        print('the {} th problem result is: {}, {}'.format(
            p, fits.mean(), fits.std()))
        print('the {} th problem cost time: {}'.format(p, time.time()-start))
