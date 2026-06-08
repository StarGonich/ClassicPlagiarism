def ans():
    n=int(input())
    t=int(input())
    times=[]
    ftimes=[]
    for _ in range(n):
        t1,t2=map(int,input().split())
        times.append([t1,t2])
        ftimes.append(t1)


    r=0
    for start in range(times[0][0]-1,times[-1][1]-t+1):
        rtime=0
        for i in range(start,start+3600+1):
            if i>times[r][0] and i<times[r][1]:
                rtime+=1
            if i==times[r][1]:
                r+=1
        if rtime>t:
            return start
    return -1


print(ans())
