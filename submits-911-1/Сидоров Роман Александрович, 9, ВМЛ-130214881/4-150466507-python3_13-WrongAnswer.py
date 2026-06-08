import math
math.gcd
n = int(input())
k = int(input())
men = 10^25
for i in range(k + 1):
    p = n + 1 + i
    nok = p * k // math.gcd(n, p)
    if nok < men:
        p1 = p
print(p)