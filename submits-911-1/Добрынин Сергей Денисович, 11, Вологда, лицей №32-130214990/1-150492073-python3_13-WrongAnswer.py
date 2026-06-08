h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
nc=0
mk=0
if (h1==h2) and (m1==m2):
    if (h1==m1) or (h1==m1//10+m1%10*10) or (h1//10+m1%10==h1%10+m1//10):
        nc+=1
elif h1<h2:
    for h in range (h1,h2+1):
        for m in range (0,59+1):
            if (h==m) or (h==m//10+m%10*10) or (h//10+m%10==h%10+m//10):
                nc+=1
    for m in range(0,m1):
        if (h1==m) or (h1==m//10+m%10*10) or (h1//10+m%10==h1%10+m//10):
                mk+=1
    for m in range(m2+1,59+1):
        if (h2==m) or (h2==m//10+m%10*10) or (h2//10+m%10==h2%10+m//10):
                mk+=1
    nc=nc-mk
elif h1>h2:
    for h in range (h1,23+1):
        for m in range (0,59+1):
            if (h==m) or (h==m//10+m%10*10) or (h//10+m%10==h%10+m//10):
                nc+=1
    for m in range(0,m1):
        if (h1==m) or (h1==m//10+m%10*10) or (h1//10+m%10==h1%10+m//10):
                mk+=1
    for h in range (0,h2+1):
        for m in range (0,59+1):
            if (h==m) or (h==m//10+m%10*10) or (h//10+m%10==h%10+m//10):
                nc+=1
    for m in range(m2+1,59+1):
        if (h2==m) or (h2==m//10+m%10*10) or (h2//10+m%10==h2%10+m//10):
                mk+=1
    nc=nc-mk
else:
    for h in range (h1,23+1):
        for m in range (0,59+1):
            if (h==m) or (h==m//10+m%10*10) or (h//10+m%10==h%10+m//10):
                nc+=1
    for m in range(0,m1):
        if (h1==m) or (h1==m//10+m%10*10) or (h1//10+m%10==h1%10+m//10):
                mk+=1
    for h in range (0,h2+1):
        for m in range (0,59+1):
            if (h==m) or (h==m//10+m%10*10) or (h//10+m%10==h%10+m//10):
                nc+=1
    for m in range(m2+1,59+1):
        if (h2==m) or (h2==m//10+m%10*10) or (h2//10+m%10==h2%10+m//10):
                mk+=1
    nc=nc-mk
print (nc)
