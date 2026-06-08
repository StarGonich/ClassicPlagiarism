from math import lcm
n = int(input())
k = int(input())
minLCM = float("inf")
ans = -1

for p in range(n + 1, n + k + 1):
	bim = lcm(n, p)
	if bim < minLCM:
		minLCM = bim
		ans = p
		
print(ans)
