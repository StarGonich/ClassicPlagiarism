import sys
import math

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    if a == 0 or b == 0:
        return 0
    return (a * b) // gcd(a, b)

n = int(sys.stdin.readline())
k = int(sys.stdin.readline())

divisors = set()
for i in range(1, int(math.sqrt(n)) + 1):
    if n % i == 0:
        divisors.add(i)
        divisors.add(n // i)

best_p = n + 1
min_lcm = lcm(n, best_p)

for d in divisors:
    p_candidate = ((n // d) + 1) * d
    if p_candidate <= n + k:
        current_lcm = lcm(n, p_candidate)
        if current_lcm < min_lcm:
            min_lcm = current_lcm
            best_p = p_candidate
        elif current_lcm == min_lcm:
            best_p = min(best_p, p_candidate)

print(best_p)
