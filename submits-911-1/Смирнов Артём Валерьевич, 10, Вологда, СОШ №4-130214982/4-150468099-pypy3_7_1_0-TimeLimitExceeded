# Optimized Code to Find Power
import math
import sys

def find_power(n, k):
    min_lcm = float('inf')
    best_p = n + 1
    
    for p in range(n + 1, n + k + 1):
        lcm = (n * p) // math.gcd(n, p)
        if lcm < min_lcm:
            min_lcm = lcm
            best_p = p
            
    return best_p

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    k = int(sys.stdin.readline().strip())
    print(find_power(n, k))