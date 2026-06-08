def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def get_divisors(n):
    divisors = set()
    i = 1
    while i * i <= n:
        if n % i == 0:
            divisors.add(i)
            divisors.add(n // i)
        i += 1
    return divisors

n = int(input())
k = int(input())

divs = get_divisors(n)

min_lcm = None
result_p = None

for d in divs:
    start = (n + 1 + d - 1) // d * d
    if start > n + k:
        continue
    p = start
    if p <= n + k:
        current_gcd = gcd(n, p)
        lcm = (n // current_gcd) * p
        if min_lcm is None or lcm < min_lcm:
            min_lcm = lcm
            result_p = p

print(result_p)