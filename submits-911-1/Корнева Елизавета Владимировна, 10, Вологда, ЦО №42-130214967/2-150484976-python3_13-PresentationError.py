n=int(input())
m=0
for i in range (1,100):
    if i%i==0:
        m=m+1   
    if m==n:
        break
print (m)
print (i)