n = int(input())
t = int(input())
s = []
t3 = 0
k = 0
for i in range(n):
    t1, t2 = map(int, input().split())

    s = s + [0] * (t1 - t3 - 1)
    s = s + [1] * (t2 - t1 + 1)
    t3 = t2
for i in range(0, max(len(s) - 3599, len(s))):
    l = min(i + 3600, len(s))
    if sum(s[int(i): int(l + 1)]) > t + 1:
        print(i + 2)
        k = 1
        break
if k == 0:
    print(-1)
    