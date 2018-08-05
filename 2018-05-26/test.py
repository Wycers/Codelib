
d = [5, -7, 4]
ans = 0
c = 3
for i in range(c):
    s = 0
    for j in range(i):
        s += d[j]
    ans -= (i + 1 + 1) * s
for i in range(c):
    ans += (i + 1 + c + 2) * (c - i - 1 + 1) / 2 * d[i]
print(ans)