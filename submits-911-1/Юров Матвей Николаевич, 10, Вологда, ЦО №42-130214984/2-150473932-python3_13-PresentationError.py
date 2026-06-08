from math import *
sum=0
div=[]
n=int(input())
for i in range(1,10**7):
    for j in range(1,i//2+1):
        if i%j==0:
            div.append(j)
    if i%n==0 and i!=n and len(div)>=n:
        print(i)
        if len(div)==n:
            for k in range(n):
                print(div[k],end=" ")
        #elif len(div)>n:
        break;
    div=[]
    