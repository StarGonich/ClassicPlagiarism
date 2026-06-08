import math

def solve():
    n = int(input())
    k = int(input())
    
    best_p = n + 1
    best_lcm = n * (n + 1) // math.gcd(n, n + 1)
    
    for d in range(1, int(math.sqrt(n)) + 2):
        if n % d == 0:
            for divisor in [d, n // d]:
                p_candidate = (n // divisor + 1) * divisor
                if n + 1 <= p_candidate <= n + k:
                    lcm_candidate = n * p_candidate // math.gcd(n, p_candidate)
                    if lcm_candidate < best_lcm or (lcm_candidate == best_lcm and p_candidate < best_p):
                        best_lcm = lcm_candidate
                        best_p = p_candidate
    
    print(best_p)

if name == "__main__":
    solve()