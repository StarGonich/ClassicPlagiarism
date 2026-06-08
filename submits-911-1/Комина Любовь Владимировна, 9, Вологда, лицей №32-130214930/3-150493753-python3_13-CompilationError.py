n = int(input())
T = int(input())
a = [tuple(map(int,input().split())) for _ in fange(n)]

l = s = 0
r = -1
for i in range(n):
s += a[i][1] - a[i][0]
while a[i][1] - a[l][0] >= 3600:
s -= a[l][1] - a[l][0]
l += 1
if s > T:
r = max(a[1][0], a[i][1] - 3600)
break
print(r)