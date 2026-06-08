N=int(input())
T=int(input())
count=0
for _ in range (N):
    t1,t2=map(int,input().split())
    if t1<=T<t2 or t1<=T+3600<t2:
        count+=1
if count>0:
    print(count)
else:
        print(-1)