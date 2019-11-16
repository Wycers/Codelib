import numpy as np
import random
import time

COLOR_BLACK = -1
COLOR_WHITE = 1
COLOR_NONE = 0

N = 5
T = 0.6
random.seed(0)
STEP = 5

class AI(object):
    def __init__(self, chessboard_size, color, time_out):
        self.chessboard_size = chessboard_size

        self.color = color

        self.time_out = time_out

        self.candidate_list = []

        self.direction = [[ 1, -1], [1, 0], [1, 1], [0, 1]]

        self.score_tree()

        self.root = None

    def go(self, chessboard):
        # print(chessboard)
        if np.count_nonzero(chessboard) == 0:
            self.candidate_list = [(7, 7)]
            return

        self.candidate_list.clear()

        # self.h(chessboard)
        self.minimax(chessboard, 0, None)

        if len(self.candidate_list) == 0:
            idx = np.where(chessboard == COLOR_NONE)
            idx = list(zip(idx[0], idx[1]))
            pos_idx = random.randint(0, len(idx) - 1)
            new_pos = idx[pos_idx]
            self.candidate_list.append(new_pos)
        print(self.candidate_list)
        # assert chessboard[new_pos[0], new_pos[1]] == COLOR_NONE

    def legal(self, x, y):
        if x < 0 or x >= self.chessboard_size:
            return False
        if y < 0 or y >= self.chessboard_size:
            return False
        return True

    def cal_tag(self, s):
        res = 0
        for i in range(7):
            res += s[i] << (7 - i - 1)
        return res

    def score_tree(self):
        self.score = [x for x in range(128)]
        self.score[0] = 0 # [0, 0, 0, 0, 0, 0, 0] 0
        self.score[1] = 0 # [0, 0, 0, 0, 0, 0, 1] 1
        self.score[2] = 10 # [0, 0, 0, 0, 0, 1, 0] 2
        self.score[3] = 10 # [0, 0, 0, 0, 0, 1, 1] 3
        self.score[4] = 10 # [0, 0, 0, 0, 1, 0, 0] 4
        self.score[5] = 10 # [0, 0, 0, 0, 1, 0, 1] 5
        self.score[6] = 100 # [0, 0, 0, 0, 1, 1, 0] 6
        self.score[7] = 100 # [0, 0, 0, 0, 1, 1, 1] 7
        self.score[8] = 10 # [0, 0, 0, 1, 0, 0, 0] 8
        self.score[9] = 10 # [0, 0, 0, 1, 0, 0, 1] 9
        self.score[10] = 100 # [0, 0, 0, 1, 0, 1, 0] 10
        self.score[11] = 100 # [0, 0, 0, 1, 0, 1, 1] 11
        self.score[12] = 100 # [0, 0, 0, 1, 1, 0, 0] 12
        self.score[13] = 100 # [0, 0, 0, 1, 1, 0, 1] 13
        self.score[14] = 1500 # [0, 0, 0, 1, 1, 1, 0] 14
        self.score[15] = 1000 # [0, 0, 0, 1, 1, 1, 1] 15
        self.score[16] = self.score[4] # [0, 0, 1, 0, 0, 0, 0]
        self.score[17] = 10 # [0, 0, 1, 0, 0, 0, 1] 17
        self.score[18] = 100 # [0, 0, 1, 0, 0, 1, 0] 18
        self.score[19] = 100 # [0, 0, 1, 0, 0, 1, 1] 19
        self.score[20] = 100 # [0, 0, 1, 0, 1, 0, 0] 20
        self.score[21] = 100 # [0, 0, 1, 0, 1, 0, 1] 21
        self.score[22] = 1000 # [0, 0, 1, 0, 1, 1, 0] 22
        self.score[23] = 1000 # [0, 0, 1, 0, 1, 1, 1] 23
        self.score[24] = self.score[12] # [0, 0, 1, 1, 0, 0, 0]
        self.score[25] = 100 # [0, 0, 1, 1, 0, 0, 1] 25
        self.score[26] = 1000 # [0, 0, 1, 1, 0, 1, 0] 26
        self.score[27] = 1000 # [0, 0, 1, 1, 0, 1, 1] 27
        self.score[28] = 1500 # [0, 0, 1, 1, 1, 0, 0] 28
        self.score[29] = 1000 # [0, 0, 1, 1, 1, 0, 1] 29
        self.score[30] = 50000 # [0, 0, 1, 1, 1, 1, 0] 30
        self.score[31] = 10000 # [0, 0, 1, 1, 1, 1, 1] 31
        self.score[32] = self.score[2] # [0, 1, 0, 0, 0, 0, 0]
        self.score[33] = 100 # [0, 1, 0, 0, 0, 0, 1] 33
        self.score[34] = 100 # [0, 1, 0, 0, 0, 1, 0] 34
        self.score[35] = 200 # [0, 1, 0, 0, 0, 1, 1] 35
        self.score[36] = self.score[18] # [0, 1, 0, 0, 1, 0, 0]
        self.score[37] = 100 # [0, 1, 0, 0, 1, 0, 1] 37
        self.score[38] = 1000 # [0, 1, 0, 0, 1, 1, 0] 38
        self.score[39] = 1000 # [0, 1, 0, 0, 1, 1, 1] 39
        self.score[40] = self.score[10] # [0, 1, 0, 1, 0, 0, 0]
        self.score[41] = 100 # [0, 1, 0, 1, 0, 0, 1] 41
        self.score[42] = 1000 # [0, 1, 0, 1, 0, 1, 0] 42
        self.score[43] = 1000 # [0, 1, 0, 1, 0, 1, 1] 43
        self.score[44] = self.score[26] # [0, 1, 0, 1, 1, 0, 0]
        self.score[45] = 1000 # [0, 1, 0, 1, 1, 0, 1] 45
        self.score[46] = 15000 # [0, 1, 0, 1, 1, 1, 0] 46
        self.score[47] = 10000 # [0, 1, 0, 1, 1, 1, 1] 47
        self.score[48] = self.score[6] # [0, 1, 1, 0, 0, 0, 0]
        self.score[49] = 100 # [0, 1, 1, 0, 0, 0, 1] 49
        self.score[50] = self.score[38] # [0, 1, 1, 0, 0, 1, 0]
        self.score[51] = 1000 # [0, 1, 1, 0, 0, 1, 1] 51
        self.score[52] = self.score[22] # [0, 1, 1, 0, 1, 0, 0]
        self.score[53] = 1000 # [0, 1, 1, 0, 1, 0, 1] 53
        self.score[54] = 12000 # [0, 1, 1, 0, 1, 1, 0] 54
        self.score[55] = 10000 # [0, 1, 1, 0, 1, 1, 1] 55
        self.score[56] = self.score[14] # [0, 1, 1, 1, 0, 0, 0]
        self.score[57] = 1000 # [0, 1, 1, 1, 0, 0, 1] 57
        self.score[58] = self.score[46] # [0, 1, 1, 1, 0, 1, 0]
        self.score[59] = 10000 # [0, 1, 1, 1, 0, 1, 1] 59
        self.score[60] = self.score[30] # [0, 1, 1, 1, 1, 0, 0]
        self.score[61] = 50000 # [0, 1, 1, 1, 1, 0, 1] 61
        self.score[62] = 100000 # [0, 1, 1, 1, 1, 1, 0] 62
        self.score[63] = 100000 # [0, 1, 1, 1, 1, 1, 1] 63
        self.score[64] = self.score[1] # [1, 0, 0, 0, 0, 0, 0]
        self.score[65] = 0 # [1, 0, 0, 0, 0, 0, 1] 65
        self.score[66] = self.score[33] # [1, 0, 0, 0, 0, 1, 0]
        self.score[67] = 10 # [1, 0, 0, 0, 0, 1, 1] 67
        self.score[68] = self.score[17] # [1, 0, 0, 0, 1, 0, 0]
        self.score[69] = 20 # [1, 0, 0, 0, 1, 0, 1] 69
        self.score[70] = self.score[49] # [1, 0, 0, 0, 1, 1, 0]
        self.score[71] = 100 # [1, 0, 0, 0, 1, 1, 1] 71
        self.score[72] = self.score[9] # [1, 0, 0, 1, 0, 0, 0]
        self.score[73] = 20 # [1, 0, 0, 1, 0, 0, 1] 73
        self.score[74] = self.score[41] # [1, 0, 0, 1, 0, 1, 0]
        self.score[75] = 100 # [1, 0, 0, 1, 0, 1, 1] 75
        self.score[76] = self.score[25] # [1, 0, 0, 1, 1, 0, 0]
        self.score[77] = 100 # [1, 0, 0, 1, 1, 0, 1] 77
        self.score[78] = self.score[57] # [1, 0, 0, 1, 1, 1, 0]
        self.score[79] = 1000 # [1, 0, 0, 1, 1, 1, 1] 79
        self.score[80] = self.score[5] # [1, 0, 1, 0, 0, 0, 0]
        self.score[81] = self.score[69] # [1, 0, 1, 0, 0, 0, 1]
        self.score[82] = self.score[37] # [1, 0, 1, 0, 0, 1, 0]
        self.score[83] = 100 # [1, 0, 1, 0, 0, 1, 1] 83
        self.score[84] = self.score[21] # [1, 0, 1, 0, 1, 0, 0]
        self.score[85] = 100 # [1, 0, 1, 0, 1, 0, 1] 85
        self.score[86] = self.score[53] # [1, 0, 1, 0, 1, 1, 0]
        self.score[87] = 1000 # [1, 0, 1, 0, 1, 1, 1] 87
        self.score[88] = self.score[13] # [1, 0, 1, 1, 0, 0, 0]
        self.score[89] = self.score[77] # [1, 0, 1, 1, 0, 0, 1]
        self.score[90] = self.score[45] # [1, 0, 1, 1, 0, 1, 0]
        self.score[91] = 1000 # [1, 0, 1, 1, 0, 1, 1] 91
        self.score[92] = self.score[29] # [1, 0, 1, 1, 1, 0, 0]
        self.score[93] = 1000 # [1, 0, 1, 1, 1, 0, 1] 93
        self.score[94] = self.score[61] # [1, 0, 1, 1, 1, 1, 0]
        self.score[95] = 10000 # [1, 0, 1, 1, 1, 1, 1] 95
        self.score[96] = self.score[3] # [1, 1, 0, 0, 0, 0, 0]
        self.score[97] = self.score[67] # [1, 1, 0, 0, 0, 0, 1]
        self.score[98] = self.score[35] # [1, 1, 0, 0, 0, 1, 0]
        self.score[99] = 100 # [1, 1, 0, 0, 0, 1, 1] 99
        self.score[100] = self.score[19] # [1, 1, 0, 0, 1, 0, 0]
        self.score[101] = self.score[83] # [1, 1, 0, 0, 1, 0, 1]
        self.score[102] = self.score[51] # [1, 1, 0, 0, 1, 1, 0]
        self.score[103] = 1000 # [1, 1, 0, 0, 1, 1, 1] 103
        self.score[104] = self.score[11] # [1, 1, 0, 1, 0, 0, 0]
        self.score[105] = self.score[75] # [1, 1, 0, 1, 0, 0, 1]
        self.score[106] = self.score[43] # [1, 1, 0, 1, 0, 1, 0]
        self.score[107] = 1000 # [1, 1, 0, 1, 0, 1, 1] 107
        self.score[108] = self.score[27] # [1, 1, 0, 1, 1, 0, 0]
        self.score[109] = self.score[91] # [1, 1, 0, 1, 1, 0, 1]
        self.score[110] = self.score[59] # [1, 1, 0, 1, 1, 1, 0]
        self.score[111] = 10000 # [1, 1, 0, 1, 1, 1, 1] 111
        self.score[112] = self.score[7] # [1, 1, 1, 0, 0, 0, 0]
        self.score[113] = self.score[71] # [1, 1, 1, 0, 0, 0, 1]
        self.score[114] = self.score[39] # [1, 1, 1, 0, 0, 1, 0]
        self.score[115] = self.score[103] # [1, 1, 1, 0, 0, 1, 1]
        self.score[116] = self.score[23] # [1, 1, 1, 0, 1, 0, 0]
        self.score[117] = self.score[87] # [1, 1, 1, 0, 1, 0, 1]
        self.score[118] = self.score[55] # [1, 1, 1, 0, 1, 1, 0]
        self.score[119] = 10000 # [1, 1, 1, 0, 1, 1, 1] 119
        self.score[120] = self.score[15] # [1, 1, 1, 1, 0, 0, 0]
        self.score[121] = self.score[79] # [1, 1, 1, 1, 0, 0, 1]
        self.score[122] = self.score[47] # [1, 1, 1, 1, 0, 1, 0]
        self.score[123] = self.score[111] # [1, 1, 1, 1, 0, 1, 1]
        self.score[124] = self.score[31] # [1, 1, 1, 1, 1, 0, 0]
        self.score[125] = self.score[95] # [1, 1, 1, 1, 1, 0, 1]
        self.score[126] = self.score[63] # [1, 1, 1, 1, 1, 1, 0]
        self.score[127] = 100000 # [1, 1, 1, 1, 1, 1, 1] 127

    def h(self, chessboard, color):
        size = self.chessboard_size
        player = [{}, {}]
        res_s = np.zeros((size, size), dtype=int)
        res_s[7, 7] = 5
        for i in range(size):
            for j in range(size):
                for x, y in self.direction:
                    if self.legal(i + (N - 1) * x, j + (N - 1) * y) is False:
                        continue
                    line = [int(chessboard[i + k * x, j + k * y]) for k in range(N)]
                    if line.count(COLOR_NONE) == 5:
                        continue
                    p = 0
                    if line.count(-color) + line.count(COLOR_NONE) == 5:
                        p = -color
                    elif line.count(color) + line.count(COLOR_NONE) == 5:
                        p = color
                    else:
                        continue

                    front = chessboard[i - x, j - y] if self.legal(i - x, j - y) else None
                    end = chessboard[i + N * x, j + N * y] if self.legal(i + N * x, j + N * y) else None

                    front_tag = 1 if front is None or (front != 0 and front != chessboard[i, j]) else 0
                    end_tag = 1 if end is None or (end != 0 and end != chessboard[i, j]) else 0

                    for k in range(N):
                        if line[k] != COLOR_NONE:
                            continue
                        line[k] = color
                        res = [front_tag]
                        res.extend([1 if g != COLOR_NONE and g == p else 0 for g in line])
                        res.append(end_tag)
                        scorea = self.score[self.cal_tag(res)]

                        line[k] = -color
                        res = [front_tag]
                        res.extend([1 if g != COLOR_NONE and g == p else 0 for g in line])
                        res.append(end_tag)
                        scoreb = self.score[self.cal_tag(res)]
                        line[k] = COLOR_NONE
                        res_s[i + k * x, j + k * y] += scorea + T * scoreb
                        # if chessboard[i + k * x, j + k * y] == COLOR_NONE:
                        #     if chessboard[i, j] == self.color:
                        #         res_s[i + k * x, j + k * y] += T * score
                        #     else:
                        #         res_s[i + k * x, j + k * y] += score

        return res_s


    def evaluate(self, chessboard):
        # print(chessboard)
        size = self.chessboard_size
        res = 0
        for i in range(size):
            for j in range(size):
                for x, y in self.direction:
                    if self.legal(i + (N - 1) * x, j + (N - 1) * y) is False:
                        continue
                    line = [int(chessboard[i + k * x, j + k * y]) for k in range(N)]
                    if line.count(COLOR_NONE) == 5:
                        continue
                    p = 0
                    if line.count(-self.color) + line.count(COLOR_NONE) == 5:
                        p = -self.color
                    elif line.count(self.color) + line.count(COLOR_NONE) == 5:
                        p = self.color
                    else:
                        continue
                    # print(i,j ,line)
                    front = chessboard[i - x, j - y] if self.legal(i - x, j - y) else None
                    end = chessboard[i + N * x, j + N * y] if self.legal(i + N * x, j + N * y) else None

                    front_tag = 1 if front is None or (front != 0 and front != chessboard[i, j]) else 0
                    end_tag = 1 if end is None or (end != 0 and end != chessboard[i, j]) else 0


                    tmp = [front_tag]
                    tmp.extend([1 if g != COLOR_NONE and g == p else 0 for g in line])
                    tmp.append(end_tag)

                    # print('+' if p == self.color else '-', self.score[self.cal_tag(tmp)])
                    if p == self.color:
                        res += self.score[self.cal_tag(tmp)]
                    else:
                        res -= self.score[self.cal_tag(tmp)]
        return res

    def minimax(self, chessboard, now, peer):
        if now == STEP + 1:
            # print(chessboard)
            # print("score => ", self.evaluate(chessboard))
            return self.evaluate(chessboard)
        size = self.chessboard_size
        res = None
        pos = None

        gg = self.h(chessboard, self.color if now & 1 == 0 else -self.color)
        # print(gg)
        avaiables = []
        for i in range(size):
            for j in range(size):
                if chessboard[i, j] != COLOR_NONE:
                    continue
                avaiables.append((i, j))
        # print(avaiables)
        avaiables = sorted(avaiables, key=lambda a: gg[a], reverse=True)[:3]

        # print("==>", now, avaiables)
        # print("==>", [gg[x] for x in avaiables])

        for i, j in avaiables:
            if chessboard[i, j] != COLOR_NONE:
                continue
            if now & 1 == 1:
                # Min layer, last layer is Max layer
                chessboard[i, j] = -self.color
                # print(now, i, j)
                if res is None:
                    res = self.minimax(chessboard, now + 1, None)
                    pos = (i, j)
                else:
                    tmp = self.minimax(chessboard, now + 1, res)
                    if tmp < res:
                        res = tmp
                    if peer == None:
                        pass
                    else:
                        if tmp < peer:
                            # print("cnt")
                            chessboard[i, j] = COLOR_NONE
                            return tmp

                chessboard[i, j] = COLOR_NONE
            else:
                # Max layer, last layer is Min layer
                chessboard[i, j] = self.color
                # print(now, i, j)
                if res is None:
                    res = self.minimax(chessboard, now + 1, None)
                    pos = (i, j)
                else:
                    tmp = self.minimax(chessboard, now + 1, res)
                    if tmp > res:
                        # print(tmp, res)
                        # print((i, j), pos)
                        res = tmp
                        pos = (i, j)

                    if peer == None:
                        pass
                    else:
                        if tmp > peer:
                            # print("cnt")
                            chessboard[i, j] = COLOR_NONE
                            return tmp

                chessboard[i, j] = COLOR_NONE
        if pos == None:
            pos = (size // 2, size // 2)
        if now == 0:
            # print(res)
            self.candidate_list.append(pos)
        return res


if __name__ == "__main__":
    XD = AI(15, -1, 5)
        #
    chessboard = np.zeros((15, 15), dtype=np.int)
    chessboard[2, 2] = 1
    chessboard[3, 3] = 1
    chessboard[4, 4] = 1
    chessboard[5, 6] = 1
    chessboard[5, 8] = 1
    chessboard[1:3, 11] = -1
    chessboard[3, 9:11] = -1
    chessboard[6, 13] = -1
    XD.go(chessboard)
