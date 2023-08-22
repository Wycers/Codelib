import random

def work(n):
    a = [x for x in range(0, n)]
    random.shuffle(a)

    for i in range(0, n):
        a[i] += 1
    # print(a)


if __name__ == "__main__":
    work(10)
