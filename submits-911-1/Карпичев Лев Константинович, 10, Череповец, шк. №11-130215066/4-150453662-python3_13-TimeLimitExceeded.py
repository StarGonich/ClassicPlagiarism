from math import *
n = int(input())
k = int(input())
a = 0
a1 = 0
p2 = 0
for p in range(n + 1, n + k + 1):
    a = lcm(n, p)
    if a1 == 0:
        a1 = a
        p2 = p
    elif a < a1:
        a1 = a
        p2 = p
print(p2)