H=int(input())
M=int(input())
h=int(input())
m=int(input())
a=1
b=1
c=1
d=1
q=0
n=M//10+10*(M%10)
while H!=h or M!=m:
    a==H//10
    b==H%10
    c==M//10
    d==M%10
    if H==M or H==c+10*d or (a+3==b+2==c+1==d):
        q+=1
    if M==59 and H==23:
        M=0
        H=0
    elif M==59:
        M=0
        H+=1
    else:
        M+=1    
print(q)
