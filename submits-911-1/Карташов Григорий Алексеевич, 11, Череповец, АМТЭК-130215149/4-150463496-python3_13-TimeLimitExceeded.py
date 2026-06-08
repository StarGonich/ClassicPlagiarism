from math import lcm
n = int(input())
k = int(input())
ans = []
for i in range(n + 1, n + k):
    ans.append((lcm(n, i), i))
print(min(ans)[-1])