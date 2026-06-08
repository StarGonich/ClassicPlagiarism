import math

n = int(input())
k = int(input())

def get_divisors(x):
    divisors = set()
    for i in range(1, int(x**0.5)+1):
        if x % i == 0:
            divisors.add(i)
            divisors.add(x // i)
    return divisors

best_p = n + 1
min_lcm = n * best_p

for d in get_divisors(n):
    m = (n // d) + 1
    p = m * d
    if n + 1 <= p <= n + k:
        lcm = n * p // math.gcd(n, p)
        if lcm < min_lcm:
            min_lcm = lcm
            best_p = p

print(best_p)