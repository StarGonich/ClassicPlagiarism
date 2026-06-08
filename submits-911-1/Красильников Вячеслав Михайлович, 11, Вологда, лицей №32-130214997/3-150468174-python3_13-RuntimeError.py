cnt = 0
rem = 0
cnt1 = 0
cnt2 = 0
for _ in range(N):
    c+=1
    cnt1 = 0
    t = input().split()
    t1 = int(t[0])
    t2 = int(t[1])
    ti = t2-t1
    while t1>I:
        t1-=I
        t2-=I
        cnt1 +=1
    if cnt1 != cnt2:
        rem = 0
    if t2 < I:
        if T<(ti + rem):
            cnt = 1
        else:
            rem += ti
    else:
        if T < ( I - t1 + rem):
            cnt = 2
        else:
            rem = 0
            if T < t2 - I:
                cnt = 3
            else:
                rem += I - (I - t2)
    cnt2 = cnt1
    if cnt != 0:
        cnnt = cnt
        break
for _ in range(N-c + 1):
    u = input()
if cnnt == 0:
    print(-1)
elif cnnt == 1:
    print(t1+(T-rem)+1)
elif cnnt == 2:
    print(t1+(T-rem) + 1)
elif cnnt == 3:
    print(T +1)

            