n = int(input())
cnt = 0
ch = 0
a = []
while cnt != n:
    ch +=1
    for i in range(1,ch//2 + 1):
        if ch % i == 0:
            cnt += 1
            a.append(i)
    if cnt == n and sum(a) == ch:
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
