n = int(input())
a = list(map(int, input().split()))
fi = la = 0
otr = []
for i in range(1,n):
    if a[i] == a[i-1] + 1:
        la = i
    else:
        otr.append((fi, la))
        fi = la = i
otr.append((fi, la))
if len(otr) == 1 or len(otr) > 5:
    print(-1)
else:
    for i in range(len(otr)-1):
        for j in range(i + 1, len(otr)):
            q = otr.copy()
            q[i], q[j] = q[j], q[i]
            t=[(a[x],a[y]) for x,y in q]
            if t == sorted(t):
                print(otr[i][0]+1, otr[i][1]-otr[i][0]+1)
                print(otr[j][0]+1, otr[j][1]-otr[j][0]+1)
                exit()
    print(-1)
