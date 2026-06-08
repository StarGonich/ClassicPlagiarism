n = int(input())
x=False
i_answ = -1
b=[]
for i in range(1,32000):
    a = set()
    # берем первые два множителя
    x, y = i, 1
    for j in range(100):
        # добавляем их в множество
        a.add(x)
        a.add(y)
        # меняем множители дальше
        if i % (y + 1) == 0:
            y += 1
            x = i // y
    a = list(a)
    a.sort(reverse=True)
    f = 0
    g = n
    while g<len(a):
        if sum(a[f:g]) == i:
            i_answ = i
            b = a[f:g]
            x=True
            break
        else:
            f+=1
            g+=1

if x == False:
    print(-1)
else:
    print(i_answ)
    print(*b)

