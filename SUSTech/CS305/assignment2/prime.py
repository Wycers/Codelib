from math import ceil, sqrt

def check_prime(n: int) -> bool:
    if n < 2:
        return False
    for i in range(2, ceil(sqrt(n) + 0.5)):
        if n % i == 0:
            return False
    return True

def find_prime(start: int, end: int) -> list:
    res = []
    for i in range(start, end + 1):
        if check_prime(i) == True:
            res.append(i)
    return res

if __name__ == "__main__":
    print(find_prime(1, 10))
    print(find_prime(100, 1000))
