x=int(input())
y=int(input())
a=int(input())
b=int(input())
k=0
n=x*60+y
e=a*60+b
for i in range (x,a+1):
    h=i
    if n<=(h*60+h)<=e:
        k+=1
    if n<=(h*60+((h%10)*10+h//10))<=e:
        k+=1
    if n<=(1*60+23)<=e:
        k+=1
    if n<=(12*60+34)<=e:
        k+=1
    if n<=(23*60+45)<=e:
        k+=1
print(k)
    
    
    