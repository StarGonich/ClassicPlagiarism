n = int(input()) #кол-во рекламных вставок
t = int(input()) #макс время рекламы
m = [] #время реклам
l = [] #промежутки
for i in range(n):
    t1,t2 = map(int, input().split())
    l.append(t1)
    l.append(t2)
    m.append(t2 - t1)
T = sum(m)
print(m)

s = 0

if T > t:
    for i in range(n):
        s += m[i]
        if s > t:
            print(s)

else:
    print(-1)