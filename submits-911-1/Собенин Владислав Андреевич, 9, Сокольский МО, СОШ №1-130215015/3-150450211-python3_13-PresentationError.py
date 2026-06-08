n=int(input())
t=int(input())
times=[]
for _ in range(n):
    t1,t2=map(int,input().split())
    times.append([t1,t2])


if t==3600:
    print(-1)
else:
    print(times)
