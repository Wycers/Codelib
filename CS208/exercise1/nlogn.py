import random


def merge(a, b):
    res = []
    i = j = 0
    while j < len(a) and i < len(b):
        if a[j] < b[i]:
            res.append(a[j])
            j += 1
        else:
            res.append(b[i])
            i += 1

    if j == len(a):
        for i in b[i:]:
            res.append(i)
    else:
        for i in a[j:]:
            res.append(i)

    return res

def merge_sort(a):
    if len(a) <= 1:
        return a
    mid = int(len(a)/2)
    l = merge_sort(a[:mid])
    r = merge_sort(a[mid:])
    return merge(l, r)


def work(n):
    a = [x for x in range(0, n)]
    random.shuffle(a)

    a = merge_sort(a)
    # print(a)


if __name__ == "__main__":
    work(10)
