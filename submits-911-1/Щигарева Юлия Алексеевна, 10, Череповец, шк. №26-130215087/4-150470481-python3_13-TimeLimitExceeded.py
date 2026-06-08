from math import *
n = int(input())
k = int(input())
b = []
for i in range(1, 10**12 + 1):
    if n + 1 <= i <= n + k:
        b.append(lcm(n, i))
        print(min(b))
        
