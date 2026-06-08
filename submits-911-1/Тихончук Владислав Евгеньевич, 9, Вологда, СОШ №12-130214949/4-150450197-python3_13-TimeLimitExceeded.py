import math

n = int(input())
k = int(input())

m = math.lcm(n, n + 1)
res = n + 1

for i in range(n + 2, n + k + 1):
    cur = math.lcm(n, i)
    if cur < m:
        m = cur
        res = i

print(res)