import math

def get_divisors(n):
    divisors = set()
    for i in range(1, int(math.isqrt(n)) + 1):
        if n % i == 0:
            divisors.add(i)
            divisors.add(n // i)
    return sorted(divisors, reverse=True)

def solve(n, k):
    divisors = get_divisors(n)
    for d in divisors:
        t = 1
        p = n + t * d
        while p <= n + k:
            if p >= n + 1:
                return p
            t += 1
            p = n + t * d
    return n + 1


n = int(input())
k = int(input())
print(solve(n, k))