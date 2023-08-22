import random

def work(n):
    a = [x for x in range(0, n)]
    random.shuffle(a)

    for i in range(0, n):
        for j in range(i + 1, n):
            if a[i] > a[j]:
                a[i], a[j] = a[j], a[i]
    # print(a)


if __name__ == "__main__":
    work(10)
