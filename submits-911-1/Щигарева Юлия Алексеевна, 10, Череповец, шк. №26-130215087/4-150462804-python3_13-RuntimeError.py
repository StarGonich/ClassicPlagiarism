from math import *
n = int(input())
k = int(input())
for p in range(1, 10**12 + 1):
    if p >= (n + 1) and p <= (n + k) and min(lcm(n, p)):
        print(p)