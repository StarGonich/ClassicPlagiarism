N=int(input())
T=int(input())
n=0
time=0
answer=3600
r_time=0
while n!=N:
    t1, t2 = map(int, input().split())
    r=r_time-t1
    time=time+(t2-t1)
    n=n+1
    answer=answer-(t2-t1-r); print(answer)
    if answer<0:
        answer=answer+3600-(answer)
    r_time=t2
if time>T:
    print(answer)
else:
    print(-1)