import random

def work(n):
    if n == 0:
        return
    for i in range(n):
        a = random.uniform(0, 1)
        work(i - 1)


if __name__ == "__main__":
    work(10)
