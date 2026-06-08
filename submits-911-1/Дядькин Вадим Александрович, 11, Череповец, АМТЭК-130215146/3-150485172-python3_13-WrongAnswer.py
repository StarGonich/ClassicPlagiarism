n = int(input())
t = int(input())
k = -1
f = True
for i in range(n):
    q, w = map(int, input().split())
    if w - q > t and f:
        k = w - 3600
        f = False
print(k)