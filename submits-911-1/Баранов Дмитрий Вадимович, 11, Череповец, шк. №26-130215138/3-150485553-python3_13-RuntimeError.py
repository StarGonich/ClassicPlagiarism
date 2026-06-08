n = int(input()) #кол-во рекламных вставок
t = int(input()) #макс время рекламы
m = [] #время реклам
l = [] #промежутки
for i in range(n):
    t1,t2 = map(int, input().split())
    l1.append(t1)
    l2.append(t2)
    m.append(t2 - t1)
T = sum(m)
print(m)

s = 0
res = 0
for time in range(3600, 3600 * n, 3600):
    for i in range(n):
        s1 = []
        if l2[i] <= time:
            s1.append(m[i])
        if sum(s1) > t:
            h = m[-1] - t
            res = 3600 * n - h - 1
    if res == 0:
        print(-1)

