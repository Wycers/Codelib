
a = [[0 for i in range(5000)] for i in range(5000)]
a[0][0] = 2
for i in range(1, 5000):
    a[0][i] = a[0][i - 1] + 1
    a[i][0] = a[i - 1][0] + 1

for i in range(1, 5000):
    for j in range(1, 5000):
        a[i][j] = a[i - 1][j] + a[i][j - 1]
    x, y = i + 1, i + 1
    print(i + 1, a[x - 1][y - 1] * (x + y - 1) % (1000000007))