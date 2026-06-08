n = int(input())
k = int(input())

min_lcm = None
result_p = None

for p in range(n + 1, n + k + 1):
    g = __import__("math").gcd(n, p)
    current_lcm = (n // g) * p
    if min_lcm is None or current_lcm < min_lcm:
        min_lcm = current_lcm
        result_p = p

print(result_p)