from math import lcm, gcd
n = int(input())
k = int(input())
ans = []
if n % 2 == 0:
    c = 1
else:
    c = 0
for i in range(n + 1, n + k, gcd(n, k) - 1):
    ans.append((lcm(n, i), i))
print(min(ans[1:])[-1])