n=int(input())
t=int(input())
times=[]
ftimes=[]
for _ in range(n):
    t1,t2=map(int,input().split())
    times.append([t1,t2])
    ftimes.append(t1)


if t==3600:
    print(-1)


else:
    for i in range(len(times)):
        rtime=0
        timenow=times[i][0]
        ftimes.append(timenow+3600)
        ftimes.sort()
        end=ftimes.index(timenow+3600)
        ftimes.pop(end)
        for j in range(i,end):
            rtime+=min(timenow+3600,times[j][1])-times[j][0]
        if rtime>t:
            print(timenow)
