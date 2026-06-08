n = int(input())
cnt = 0
ch = 0
a = []
while cnt != n:
    ch +=1
    for i in range(1,ch//1 + 1):
        if ch % i == 0:
            cnt += 1
            a.append(i)
    if cnt == n:
        print(ch)
        break
    else:
        cnt = 0
        a = []
a.sort()
for i in a:
    print(i, end = ' ')
