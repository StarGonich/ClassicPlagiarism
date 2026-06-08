import math

def gcd(a, b):
    """Вычисляет наибольший общий делитель двух чисел."""
    while b:
        a, b = b, a % b
    return a

def solve():
    n = int(input())
    k = int(input())

    best_p = -1
    max_gcd = -1

    for p in range(n + 1, min(n + k + 1, 2 * n + 1)):
        current_gcd = gcd(n, p)
        if current_gcd > max_gcd:
            max_gcd = current_gcd
            best_p = p

    print(best_p)

solve()