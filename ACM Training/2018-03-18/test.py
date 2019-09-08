def dfs(a):
    sum = 0
    for i in a:
        sum += i
    if sum == 0:
        return 0

    child = []
    b = a[:]
    for j in range(0, a[0]):
        b[0] = j
        #print(b, dfs(b))
        x = dfs(b)
        if x not in child:
            child.append(x)
        
    for i in range(1, len(a)):
        b = a[:]
        for j in range(a[i - 1], a[i]):
            b[i] = j
            x = dfs(b)
            if x not in child:
                child.append(x)
    
    child.sort()
    for i in range(0, len(child)):
        if child[i] != i:
            return i
    return len(child)
def dfs2(a):
    sum = 0
    for i in a:
        sum += i
    if sum == 0:
        return 0

    child = []
    for i in range(0, len(a)):
        for j in range(0, a[i]):
            b = a[:]
            b[i] = j
            if i + 1 != len(a):
                b[i + 1] = a[i] - j
            x = dfs2(b)
            if x not in child:
                child.append(x)

    child.sort()
    for i in range(0, len(child)):
        if child[i] != i:
            return i
    return len(child)


print(dfs([0, 2, 2]))
for i in range(1, 7):
    for j in range(i + 1, 7):
        for k in range(j + 1, 7):
            print([i, j, k])
            print(dfs([i, j, k]), (j - i) ^ (k - j), dfs2([j - i, k - j]))
                