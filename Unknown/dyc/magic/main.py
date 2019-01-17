import queue

def kt(a):
    fac = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]
    res = 0
    for i in range(8):
        x = 0
        for j in range(i + 1, 8):
            if a[j] < a[i]:
                x = x + 1
        res = res + fac[8 - i - 1] * x
    return res


ans = {}

q = queue.Queue()
q.put((range(1, 9), 0))
ans[0] = 0

while not q.empty():
    ori, step = q.get()

    tmp = list(ori)
    tmp.reverse()
    state = kt(tmp)
    if state not in ans:
        ans[state] = step + 1
        q.put((tmp, step + 1))

    tmp = list(ori)
    tmp[0: 3], tmp[3] = tmp[1: 4], tmp[0]
    tmp[4], tmp[5: 8] = tmp[7], tmp[4: 7]

    state = kt(tmp)
    if state not in ans:
        ans[state] = step + 1
        q.put((tmp, step + 1))

    tmp = list(ori)
    tmp[1], tmp[2], tmp[5], tmp[6] = tmp[2], tmp[5], tmp[6], tmp[1]
    state = kt(tmp)
    if state not in ans:
        ans[state] = step + 1
        q.put((tmp, step + 1))

print(ans[kt([1, 2, 3, 4, 5, 6, 7, 8])])
print(ans[kt([8, 6, 3, 5, 4, 2, 7, 1])])
print(ans[kt([2, 4, 5, 1, 8, 6, 3, 7])])

gg = ''
for i in range(40320):
    gg = gg + str(ans[i]) + ','
f = open('XD.txt', 'w')
f.write(gg)
f.close()
