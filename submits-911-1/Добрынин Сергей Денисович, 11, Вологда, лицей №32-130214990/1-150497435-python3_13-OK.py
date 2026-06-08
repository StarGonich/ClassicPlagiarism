h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
nc=0
mk=0
def ry(lk,lu):
    q1=lk//10
    q2=lk%10
    q3=lu//10
    q4=lu%10
    if (q4-q3==1) and (q3-q2==1) and (q2-q1==1):
        return(True)
    else:
        return(False)
if (h1==h2) and (m1==m2):
    if (h1==m1) or (h1==m1//10+m1%10*10) or (ry(h1,m1)):
        nc+=1
elif (h1==h2) and (m1<m2):
    for m in range (m1,m2+1):
        if (h1==m) or (h1==m//10+m%10*10) or (ry(h1,m)):
            nc+=1
elif h1<h2:
    for h in range (h1,h2+1):
        for m in range (0,59+1):
            if (h==m) or (h==m//10+m%10*10) or (ry(h,m)):
                nc+=1
    for m in range(0,m1):
        if (h1==m) or (h1==m//10+m%10*10) or (ry(h,m)):
                mk+=1
    for m in range(m2+1,59+1):
        if (h2==m) or (h2==m//10+m%10*10) or (ry(h2,m)):
                mk+=1
    nc=nc-mk
elif h1>h2:
    for h in range (h1,23+1):
        for m in range (0,59+1):
            if (h==m) or (h==m//10+m%10*10) or (ry(h,m)):
                nc+=1
    for m in range(0,m1):
        if (h1==m) or (h1==m//10+m%10*10) or (ry(h1,m)):
                mk+=1
    for h in range (0,h2+1):
        for m in range (0,59+1):
            if (h==m) or (h==m//10+m%10*10) or (ry(h,m)):
                nc+=1
    for m in range(m2+1,59+1):
        if (h2==m) or (h2==m//10+m%10*10) or (ry(h2,m)):
                mk+=1
    nc=nc-mk
else:
    for h in range (h1,23+1):
        for m in range (0,59+1):
            if (h==m) or (h==m//10+m%10*10) or (ry(h,m)):
                nc+=1
    for m in range(0,m1):
        if (h1==m) or (h1==m//10+m%10*10) or (ry(h1,m)):
                mk+=1
    for h in range (0,h2+1):
        for m in range (0,59+1):
            if (h==m) or (h==m//10+m%10*10) or (ry(h,m)):
                nc+=1
    for m in range(m2+1,59+1):
        if (h2==m) or (h2==m//10+m%10*10) or (ry(h2,m)):
                mk+=1
    nc=nc-mk
print (nc)
