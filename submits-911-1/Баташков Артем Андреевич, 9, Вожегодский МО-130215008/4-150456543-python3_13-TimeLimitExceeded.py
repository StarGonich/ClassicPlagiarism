import math

def gcd(a, b):
    while(b != 0):
        a, b = b, a % b
    return a

n = int(input())
k = int(input())

min_lcm_value = float('inf')
best_p = None

for p in range(n + 1, min(n + k + 1, 10**18)):
    lcm_value = abs(n * p // gcd(n, p))
    
    if lcm_value < min_lcm_value:
        min_lcm_value = lcm_value
        best_p = p

print(best_p)