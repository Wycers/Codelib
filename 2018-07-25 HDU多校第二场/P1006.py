from scipy.special import comb, perm

def pow(x):
    res = 1
    for i in range(1, x + 1):
        res = res * 2
    return res


n = 3
m = 4
a = 1
b = 2
ans = 0
for i in range(a, n + 1):
    for j in range(b, m + 1):
        ans += comb(n, i) * comb(m, j) * (2 ** (i * m + j * n - i * j))
print(ans)
