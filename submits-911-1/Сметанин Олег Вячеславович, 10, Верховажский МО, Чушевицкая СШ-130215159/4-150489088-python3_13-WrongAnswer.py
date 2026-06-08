import math

def lcm(a, b):
    return abs(a * b) // math.gcd(a, b)

def find_optimal_power(n, k):
    p_min = n + 1
    p_max = n + k
    optimal_p = p_min
    minimum_lcm = lcm(n, p_min)

    for p in range(p_min, p_max + 1):
        current_lcm = lcm(n, p)
        if current_lcm < minimum_lcm:
            minimum_lcm = current_lcm
            optimal_p = p

    return optimal_p