a = "ABCABD"
nx = [0] * (len(a) + 1)

i, j = 0, -1
nx[0] = -1
while i < len(a):
    if j == -1 or a[i] == a[j]:
        i, j = i + 1, j + 1
        nx[i] = j
    else:
        j = nx[j]

for i in range(0, len(a) + 1):
    print(i, nx[i])
    if nx[i] == -1:
        continue
    print(a[0: nx[i]], a[i - nx[i]: i])

