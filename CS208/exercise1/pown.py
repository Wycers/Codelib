import random

def work(n):
    if n == 0:
        return
    work(n - 1)
    work(n - 1)


if __name__ == "__main__":
    work(10)
