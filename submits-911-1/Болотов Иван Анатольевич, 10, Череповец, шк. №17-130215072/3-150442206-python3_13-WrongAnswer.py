N=int(input())
T=int(input())
t1, t2=map(int, input().split())
tt=t2-t1
if tt >=T:
    print(-1)
for i in range(N):
    tt=t2-t1
    t1+=t1
    t2+=t2
    tt+=tt
    if tt>T:
        print(tt-t1)
else:
    print(-1)