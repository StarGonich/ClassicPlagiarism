H=int(input())
M=int(input())
h=int(input())
m=int(input())
q=0
while H!=h or M!=m:
    if H==M or H==M//10+10*(M%10) or (H//10+3==H%10+2==M//10+1==M%10):
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

