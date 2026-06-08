
from math import lcm, gcd
min_n = 100000000000000
flag = True
n, k = int(input()), int(input())
for i in range(n + 1, n + k + 1, 1):
    a = (lcm(n, i))
    if (a<min_n):
        min_n = a
b = ((lcm(n, i)) * (gcd(n, i)))//n
print(b)
