n = int(input())
x = list(map(int, input().split()))
d = list(map(int, input().split()))
k = int(input())
r = 1
for i in range(k, n-1):
    if d[i] >= x[i+1] - x[i]:
        r += 1
for i in range(k, 0, -1):
    if d[i] >= x[i-1] - x[i]:
        r += 1
print(r)