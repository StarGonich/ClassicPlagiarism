from itertools import *
def deli(n):
    a=set()
    for i in range(1,int(n**0.5)+1):
        if n%i==0:
            a.add(i)
            a.add(n//i)
    return a
n=int(input())
flag=False
for i in range(1,10**9+1):
    for j in permutations(deli(i),n):
        if sum(j)==i:
            print(i)
            print(*j)
            flag=True
            break
    if flag:
        break