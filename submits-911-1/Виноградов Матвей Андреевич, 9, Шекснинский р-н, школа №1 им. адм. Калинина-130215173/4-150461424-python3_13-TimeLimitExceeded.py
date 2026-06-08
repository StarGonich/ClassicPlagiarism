def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

n = int(input())
k = int(input())

best_p = n + 1
best_lcm = lcm(n, best_p)

for p in range(n + 1, n + k + 1):
    current_lcm = lcm(n, p)
    if current_lcm < best_lcm:
        best_lcm = current_lcm
        best_p = p

print(best_p)
