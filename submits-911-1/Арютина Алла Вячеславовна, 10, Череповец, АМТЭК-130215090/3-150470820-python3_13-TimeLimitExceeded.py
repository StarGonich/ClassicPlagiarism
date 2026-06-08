n = int(input())
t = int(input())
a = [0] * (10**6)
for i in range(n):
    x, y = map(int, input().split())
    for j in range(x, y):
        a[j] += 1
m = -1
for i in range(y + 1):
    if sum(a[i:i + 3600]) > t:
        m = i
        break
print(m)