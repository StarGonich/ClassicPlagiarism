n=[0]*10**5
k=[0]*10**5
N=int(input())
t=int(input())
for i in range(0,N):
    s=input().split()
    n[i]=int(s[0])
    k[i]=int(s[1])
i=n[0]
while i<=k[N-1]-t:
    #[i;i+3600]
    c=0
    for j in range(0,N):
        #print("[",i,";",i+3600,"]")
        if i<=n[j]<=i+3600 and i<=k[j]<=i+3600:
            c+=k[j]-n[j]
            #print(c,"1",n[j],k[j])
        elif n[j]<i and i<k[j]<=i+3600:
            c+=k[j]-i
            #print(c,"2",n[j],k[j])
        elif n[j]<i and k[j]>i+3600:
            c+=3600
            #print(c,"3",n[j],k[j])
        elif n[j]<i+3600 and k[j]>=i+3600:
            c+=i+3600-n[j]
            #print(c,"4",n[j],k[j])
        elif n[j]>i+3600:
            break
        
    if c>t:
        break
    i+=(t-c)
    if c==t:
        i+=1
if i<=k[N-1]-t:
    print(i)
else:
    print(-1)