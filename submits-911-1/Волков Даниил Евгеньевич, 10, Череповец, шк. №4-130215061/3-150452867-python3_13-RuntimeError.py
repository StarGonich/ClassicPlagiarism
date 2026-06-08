N=int(input())
T=int(input())
n=0
time=0
answer=3600
while n!=N:
    t1, t2 = map(int, input().split())
    time=time+(t2-t1)
    n=n+1
    answer=answer-(t2-t1-r)
    if answer<0:
        answer=3600
if time>T:
    print(answer)
else:
    print(-1)