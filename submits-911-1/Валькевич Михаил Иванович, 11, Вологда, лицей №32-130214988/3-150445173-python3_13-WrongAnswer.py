n=int(input())
t=int(input())
s1=[]
s2=[]
for i in range(0,n):
    t1, t2 = map(int, input().split())
    s1.append(t1)
    s2.append(t2)
for p in range(0,len(s1)):
    if s2[p]-s1[p]>t:
        print(s1[p]+t-3600)
        break
