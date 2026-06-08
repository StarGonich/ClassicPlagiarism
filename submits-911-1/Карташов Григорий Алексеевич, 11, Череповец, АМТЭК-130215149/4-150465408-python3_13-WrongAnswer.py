from math import lcm
n = int(input())
k = int(input())
ans = []
for i in range(n + 1, n + k, int(n**0.5)):
    ans.append((lcm(n, i), i))
print(min(ans)[-1])