h1= int(input())
m1= int(input())
h2= int(input())
m2= int(input())
k=0
#and ( i!=11) and (i!=0) and (i!=22)
if (h1==h2) and (m1<m2):
    i = h1          
    for j in range ( m1, m2+1):
        if (i==j):
            k+=1
        elif (i%10 == j//10) and (j%10 == i//10):
            k+=1
        elif (i//10 +1== i%10) and ( i%10 +1 == j//10) and (j//10 +1== j%10):
            k+=1    
elif (h1==h2) and (m1>m2):
    i = h2          
    for j in range ( 0, m2+1):
        if (i==j):
            k+=1
        elif (i%10 == j//10) and (j%10 == i//10):
            k+=1
        elif (i//10 +1== i%10) and ( i%10 +1 == j//10) and (j//10 +1== j%10):
            k+=1    
    i = h1          
    for j in range ( m1, 60):
        if (i==j):
            k+=1
        elif (i%10 == j//10) and (j%10 == i//10):
            k+=1
        elif (i//10 +1== i%10) and ( i%10 +1 == j//10) and (j//10 +1== j%10):
            k+=1
    for i in range(h1+1,24):
        for j in range (0,60):
            if (i==j):
                k+=1
            elif (i%10 == j//10) and (j%10 == i//10):
                k+=1
            elif (i//10 +1== i%10) and ( i%10 +1 == j//10) and (j//10 +1== j%10):
                k+=1
    for i in range(0,h2):
        for j in range (0,60):
            if (i==j):
                k+=1
            elif (i%10 == j//10) and (j%10 == i//10):
                k+=1
            elif (i//10 +1== i%10) and ( i%10 +1 == j//10) and (j//10 +1== j%10):
                k+=1

    
elif (h1==h2) and (m1==m2):
    i=h1
    j=m1
    if (i==j):
        k+=1
    elif (i%10 == j//10) and (j%10 == i//10):
        k+=1
    elif (i//10 +1== i%10) and ( i%10 +1 == j//10) and (j//10 +1== j%10):
        k+=1    
else:
    for i in range(h1+1,h2):
        for j in range (0,60):
            if (i==j):
                k+=1
            elif (i%10 == j//10) and (j%10 == i//10):
                k+=1
            elif (i//10 +1== i%10) and ( i%10 +1 == j//10) and (j//10 +1== j%10):
                k+=1
    i = h1           
    for j in range ( m1, 60):
        if (i==j):
            k+=1
        elif (i%10 == j//10) and (j%10 == i//10):
            k+=1
        elif (i//10 +1== i%10) and ( i%10 +1 == j//10) and (j//10 +1== j%10):
            k+=1    
    i = h2          
    for j in range ( 0, m2+1):
        if (i==j):
            k+=1
        elif (i%10 == j//10) and (j%10 == i//10):
            k+=1
        elif (i//10 +1== i%10) and ( i%10 +1 == j//10) and (j//10 +1== j%10):
            k+=1
print (k)
    
   