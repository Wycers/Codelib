def he(x):
    for i in range(2, x):
        if (x % i == 0):
            return True
    return False
def get(x):
    cnt = 0
    for i in range(2, x + 1):
        if (x % i == 0):
            if (he(x)):
                cnt = cnt + 1

    print(x, ' ', cnt)
    cnt = 0
    for i in range(2, x + 1):
        while (x % i == 0):
            x /= i
            print(i)
            cnt = cnt + 1
    print(x, ' ', cnt)
    return cnt
max = 0
for i in range(1, 10001):
    t = get(i)
    max = t if t > max else max 
print(max)