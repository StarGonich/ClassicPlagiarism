import sys

sys.setrecursionlimit(1 << 25)
input = lambda: sys.stdin.readline().rstrip('\r\n')


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def lcm(a, b):
    return abs(a * b) // gcd(a, b)


def find_optimal_power(n, k):
    best_p = float('inf')
    min_lcm = float('inf')

    for p in range(n + 1, n + k + 1):
        current_lcm = lcm(n, p)
        if current_lcm < min_lcm:
            min_lcm = current_lcm
            best_p = p

    return best_p

n = int(input())
k = int(input())


optimal_power = find_optimal_power(n, k)

print(optimal_power)