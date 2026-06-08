N=int(input())
T=int(input())
p=0
tm=0
for i in range (N):
    t1, t2 = map(int, input().split())
    p=p+(t2-t1)
    if (t2-t1)>T:
        tm=t1
        break
if T>=p:
    print('-1')
elif T<p:
    print(tm)