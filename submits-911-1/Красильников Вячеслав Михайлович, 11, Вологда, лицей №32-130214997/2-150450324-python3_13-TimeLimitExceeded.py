n = int(input())
cnt = 0
ch = 0
a = []
y = 0
u = []
k = 0
while cnt != n:
    ch +=1
    for i in range(1,ch//2 + 1):
        if ch % i == 0:
            a.append(i)
    a.sort()
    for i in range(len(a)):
        k +=a[i]
        for j in range(len(a)):
            k += a[j]
            if a[j] in u:
                k-=a[j]
                continue
            else:
                u.append(a[j])
            if sum(u) == ch:
                break
        if sum(u) == ch:
            a = u
            break
        else:
            u = []
            k = 0
    if len(u) == n and sum(u) == ch:
        print(ch)
        a.sort()
        for i in a:
            print(i, end = ' ')
        break
    elif cnt > n:
        print(-1)
        break
    else:
        cnt = 0
        a = []
