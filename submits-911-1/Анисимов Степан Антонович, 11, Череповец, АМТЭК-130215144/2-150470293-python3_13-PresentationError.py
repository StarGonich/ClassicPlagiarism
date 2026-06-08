from math import *
n=int(input())
a=[]
p=0
def fd (a,n):
    s=[]
    k=0
    b=[]
    fl=True
    for i in range(1,int(sqrt(a))+2):
        if a%i==0:
            if sum(s)+i<=a:
                s.append(i)
                k+=1
            else:
                break
    if sum(s)==a and k==n:
        return(s)
    else:
        b=[]
        for i in range(k):
            fl=True
            b=[s[i]]
            h=0
            for j in range(i+1,k):
                if h<=n and fl:
                    if sum(b)+s[j]<a:
                        b.append(s[j])
                        h+=1
                    elif sum(b)+s[j]==a and h==n:
                        b.append(s[j])
                        return(b)
                    else:
                        b=[]
                        fl=False
                    
        if sum(b)!=a:
            return([0])
for i in range(1,10000):
    a=fd(i,n)
    if a !=[0] and a!=None:
        if sum(a)==i and i>n:
            print(i)
            print(a)
            p=1
            break
if p == 0:
    print(-1)