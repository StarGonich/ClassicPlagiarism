def nok(x,y):
       d=max(x,y)
       c=min(x,y)
       while max(c,d)%min(c,d)!=0:
              if d>c:d=d%c
              else:c=c%d
       return (x*y)/min(d,c)
n=int(input())
k=int(input())
p=n+1
m=nok(n,p)
o=p
for p in range(n+1,n+1+k):
       if nok(n,p)<m:
              m=nok(n,p)
              o=p
print(o)
       
