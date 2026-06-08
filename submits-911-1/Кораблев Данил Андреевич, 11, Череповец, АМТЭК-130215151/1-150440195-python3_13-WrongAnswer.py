h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
k = 0
f = False
while (h1-1)%24!=h2:
    h=list(str(h1))
    if h1==h2:
        for i in range(m1,m2+1):
            m = list(str(i))
            md = list(str(i*10))
            if (h==m or h==m[::-1] or h==md or h==md[::-1] or (int(h[0])+1==int(h[1]) and int(h[1])+1==int(m[0]) and int(m[0])+1==int(m[1]))):
                k+=1
    elif f:
        for i in range(0,61):
            m = list(str(i))
            if (h==m or h==m[::-1] or (int(h[0])+1==int(h[1]) and int(h[1])+1==int(m[0]) and int(m[0])+1==int(m[1]))):
                k+=1
    else:
        for i in range(m1,61):
            m = list(str(i))
            if (h==m or h==m[::-1] or (int(h[0])+1==int(h[1]) and int(h[1])+1==int(m[0]) and int(m[0])+1==int(m[1]))):
                k+=1    
    h1+=1
    f = True
print(k)