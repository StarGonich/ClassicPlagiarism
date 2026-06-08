n = int(input())
t = int(input())
k = 0
f = True
for i in range(n):
    q, w = map(int, input().split())
    if w - q > t and f:
        k = q + t - 3600
        f = False
if k == 0:
    print(-1)
elif k < 0:
    print(1)
else:
    print(k+1)