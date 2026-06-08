import math
import sys

n = int(sys.stdin.readline())
k = int(sys.stdin.readline())

left = n + 1
right = n + k

def get_divisors(x):
    divs = set()
    limit = int(math.isqrt(x))
    for i in range(1, limit + 1):
        if x % i == 0:
            divs.add(i)
            divs.add(x // i)
    return divs

min_lcm = None
result_p = None

# Проверка делителей n
for d in get_divisors(n):
    # p = d
    if left <= d <= right:
        g = math.gcd(n, d)
        lcm = (n // g) * d
        if min_lcm is None or lcm < min_lcm:
            min_lcm = lcm
            result_p = d
    # p = n // d
    p2 = n // d
    if left <= p2 <= right:
        g = math.gcd(n, p2)
        lcm = (n // g) * p2
        if min_lcm is None or lcm < min_lcm:
            min_lcm = lcm
            result_p = p2

# Также проверить границы диапазона n+1 и n+k
for p_candidate in [left, right]:
    g = math.gcd(n, p_candidate)
    lcm = (n // g) * p_candidate
    if min_lcm is None or lcm < min_lcm:
        min_lcm = lcm
        result_p = p_candidate

print(result_p)