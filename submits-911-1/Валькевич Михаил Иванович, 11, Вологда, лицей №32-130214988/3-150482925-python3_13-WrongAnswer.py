n=int(input())
t=int(input())
s1=[]
s2=[]
for i in range(0,n):
    t1, t2 = map(int, input().split())
    s1.append(t1)
    s2.append(t2)
for p in range(0,len(s1)-1):
    if s2[p]-s1[p]>t:
        print(s1[p]+t-3600)
        break
    elif s2[p+1]-s1[p+1]>t:
        print(s1[p+1]+t-3600)
        break
    else:
        print(-1)