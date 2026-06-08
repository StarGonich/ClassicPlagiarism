from math import lcm, gcd
n = int(input())
k = int(input())
ans = []
if gcd(n, n + k) == 1:
    c = 0
else:
    c = -1
if n + k > 2* n:
    for i in range(n, n + k, n):
        ans.append((lcm(n, i), i))
else:
    for i in range(n, n + k):
        ans.append((lcm(n, i), i))
print(min(ans[1:])[-1])    