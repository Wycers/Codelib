m = int(input())
a, b = 0, 2
while b < m:
    a, b = b, b * 6 - a
c, d = 0, 6
while d < m:
    c, d = d, d * 14 - c
print(min(b, d))
