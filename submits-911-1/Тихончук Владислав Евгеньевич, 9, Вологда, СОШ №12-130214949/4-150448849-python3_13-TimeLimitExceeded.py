import math

n = int(input())
k = int(input())

res = {}

p = n + 1
while p <= n + k:
    res[math.lcm(n, p)] = p
    p += 1

m = min(res.keys())
print(res[m])