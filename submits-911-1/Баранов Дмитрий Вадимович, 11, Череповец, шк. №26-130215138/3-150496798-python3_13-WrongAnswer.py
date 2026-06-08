n = int(input()) #кол-во рекламных вставок
t = int(input()) #макс время рекламы
m = [] #время реклам
l = [] #промежутки
l1 = []
l2 = []
for i in range(n):
    t1,t2 = map(int, input().split())
    l1.append(t1)
    l2.append(t2)
    m.append(t2 - t1)
T = sum(m)
#print(m) 
            #if l1[i] + 3600 * i <= time:
                #s1.remove(m[i])

s = 0
res = 0
for time in range(3600, 3600 * (n), 3600):
    s1 = []
    for i in range(n):
        if l1[i] + 3600 * (i - 1) <= time:
            s1 = []      
        if l2[i] <= time:
            s1.append(m[i])
            #print(s1, sum(s1))
            if sum(s1) > t:
                h = sum(s1) - t # 300
                #print(h)
                g = abs(3600 - l2[i])
                #print(g)
                res = g - h + 1
                print(res)
        
if res == 0:
    print(-1)

