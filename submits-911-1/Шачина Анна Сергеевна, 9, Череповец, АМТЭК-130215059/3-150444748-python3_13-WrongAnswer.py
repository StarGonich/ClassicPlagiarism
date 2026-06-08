N = int(input())
T = int(input())
b = list()
c = list()
for i in range(N):
    t1, t2 = map(int, input().split())
    b.append(t1)
    c.append(t2)
for i in range(t1, t2):
    if t2 - t1 < 3600:
        a = (-1)
    else:
        a = (t1)
print(a)