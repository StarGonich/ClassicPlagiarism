n = int(input())
t = int(input())
a = []
s = 0
ans = -1
for i in range(n):
    t1, t2 = map(int, input().split())
    a.append([t1, t2, t2 - t1])
print(0)