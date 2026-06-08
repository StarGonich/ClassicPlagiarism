from math import lcm, gcd
n = int(input())
k = int(input())
ans = []
if gcd(n, n + k) == 1:
    c = 0
else:
    c = -1
for i in range(n + 1, n + k, gcd(n, n + k) + c):
    ans.append((lcm(n, i), i))
print(min(ans)[-1])