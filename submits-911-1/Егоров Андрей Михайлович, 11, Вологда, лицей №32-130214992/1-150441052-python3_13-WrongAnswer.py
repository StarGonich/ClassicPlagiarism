def che(x,y):
       if x==y:return 1
       if x//10==x%10+1 and x//10==y//10+2 and x//10==y%10+3:return 1
       if x//10==y%10 and x%10==y//10:return 1
       else:return 0
a=int(input())
b=int(input())
c=int(input())
d=int(input())
count=0
while a!=b or c!=d:
       count+=che(a,c)
       c+=1
       if c==60:
              c=0
              a+=1
       if a==24:
              c=0
              a=0
count+=che(a,c)
print(count)

