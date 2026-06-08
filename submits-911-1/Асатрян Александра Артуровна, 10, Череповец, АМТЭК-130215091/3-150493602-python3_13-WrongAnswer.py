n = int(input())
t = int(input())
a = []
s = 0
ans = -1
for i in range(n):
    t1, t2 = map(int, input().split())
    a.append([t1, t2, t2 - t1])
k = 0
for i in range(n):
    s += a[i][2]
    if a[i][0] - a[k][0] >= 3600:
        k += 1
        s -= a[k - 1][2] 
    if s > t:
        ans = max((a[i][1] - s + t - 3599), 0)
        break
print(t2-3599)