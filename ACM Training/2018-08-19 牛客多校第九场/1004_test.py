def getx(a, b):
    c = [b[i] - a[i] for i in range(0, 5)]
    d = [c[i] - c[i - 1] for i in range(1, 5)]
    d = [0] + d
    print(d)
x, y = [0, 0, 0, 0, 0], [0, 1, 1, 1, 0]
getx(x, y)
x, y = y, [0, 1, 2, 3, 3]
getx(x, y)
x, y = y, [0, 3, 4, 5, 3]
getx(x, y)
x, y = y, [0, 3, 7, 12, 15]
getx(x, y)
x, y = y, [0, 3, 10, 22, 37]
getx(x, y)
x, y = y, [0, 3, 13, 35, 72]
getx(x, y)