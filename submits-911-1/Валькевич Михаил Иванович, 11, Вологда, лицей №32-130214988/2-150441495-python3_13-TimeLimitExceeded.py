n=int(input())
b=False
for i in range(1,10000):
    s=0
    c=0
    a=[]
    for k in range(1,i//2+1):
        if i%k==0:
            if s+k<=i:
                s+=k
                c+=1
                a.append(k)
        if s==i and c==n:
            b=True
            print(i)
            for u in range(0,len(a)):
                print(a[u], end=" ")
            break
    if b==True:
        break
if b==False:
    print(-1)