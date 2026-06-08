n=[0]*10**5
k=[0]*10**5
N=int(input())
t=int(input())
for i in range(0,N):
    s=input().split()
    n[i]=int(s[0])
    k[i]=int(s[1])
i=n[0]
while i<=k[N-1]:
    #[i;i+3600]
    c=0 # c - количество рекламыв секундах
    for j in range(0,N):
        #print("[",i,";",i+3600,"]")
        if i<=n[j]<=i+3600 and i<=k[j]<=i+3600: #если начало и конец входят в отрезок
            c+=k[j]-n[j]
            #print(c,"1",n[j],k[j])
        elif n[j]<i and i<k[j]<=i+3600: #если только конец входит в отрезок
            c+=k[j]-i
            #print(c,"2",n[j],k[j])
        elif n[j]<i and k[j]>i+3600: #если реклама длится больше чем отрезок
            c+=3600
            #print(c,"3",n[j],k[j])
        elif n[j]<i+3600 and k[j]>=i+3600: # только начало входит в список
            c+=i+3600-n[j]
            #print(c,"4",n[j],k[j])
        elif n[j]>i+3600: # перебдел, брейкай
            break
        
    if c>t:
        break
    i+=(t-c)
    if c==t:
        i+=1
if i<=k[N-1]:
    print(i)
else:
    print(-1)