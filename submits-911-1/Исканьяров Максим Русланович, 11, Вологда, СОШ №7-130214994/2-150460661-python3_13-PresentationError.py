import sys
import math

def sum_of_divisors(n):
    if n == 0:
        return 0
    
    total = 0
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            total += i
            if i != n // i:
                total += n // i
    return total

n = int(sys.stdin.readline().strip())

print(sum_of_divisors(n))
