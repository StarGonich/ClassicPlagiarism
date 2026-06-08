h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
    
col=0

if h1<h2:
    for x in range(h1,h2):
        if x==h1:
            for y in range(m1,60):
                if x==h2 and y==m2:
                    break
                if x<10:
                    x1='0'+str(x)
                else: x1=str(x)
                if y < 10:
                    y1='0'+str(y)
                else: y1=str(y)
                ti=x1+y1
                if x1==y1:
                    col+=1
                elif x1==y1[-1::-1]:
                    col+=1
                elif int(ti[0])==int(ti[1])-1 and int(ti[1])==int(ti[2])-1 and int(ti[2])==int(ti[3])-1:
                    col+=1
            if x==h2 and y==m2:
                break
        else:
            for y in range(0,60):
                if x==h2 and y==m2:
                    break
                if x<10:
                    x1='0'+str(x)
                else: x1=str(x)
                if y < 10:
                    y1='0'+str(y)
                else: y1=str(y)
                ti=x1+y1
                if x1==y1:
                    col+=1
                elif x1==y1[-1::-1]:
                    col+=1
                elif int(ti[0])==int(ti[1])-1 and int(ti[1])==int(ti[2])-1 and int(ti[2])==int(ti[3])-1:
                    col+=1
            if x==h2 and y==m2:
                break
     
            
elif h1==h2:
    if m1==m2:
        print(0)
    if m1<m2:
        for y in range(m1,m2):
            if h1<10:
                h11='0'+str(h1)
            else: h11=str(h1)
            if y < 10:
                y1='0'+str(y)
            else: y1=str(y)
            ti=h11+y1
            if h11==y1:
                col+=1
            elif h11==y1[-1::-1]:
                col+=1
            elif int(ti[0])==int(ti[1])-1 and int(ti[1])==int(ti[2])-1 and int(ti[2])==int(ti[3])-1:
                col+=1
            if y==m2:
                break
    if m1>m2:
        for x in range(h1,h2+24+1):
            if x==h1:
                for y in range(m1,60):
                    if x==h2 and y==m2:
                        break
                    if x<10:
                        x1='0'+str(x)
                    else: x1=str(x)
                    if y < 10:
                        y1='0'+str(y)
                    else: y1=str(y)
                    ti=x1+y1
                    if x1==y1:
                        col+=1
                    elif x1==y1[-1::-1]:
                        col+=1
                    elif int(ti[0])==int(ti[1])-1 and int(ti[1])==int(ti[2])-1 and int(ti[2])==int(ti[3])-1:
                        col+=1
                if x==h2 and y==m2:
                    break
            
            else:
                for y in range(0,60):
                    if x>=24:
                        x=x-24
                    if x==h2 and y==m2:
                        break
                
                    if x<10:
                        x1='0'+str(x)
                    else: x1=str(x)
                    if y < 10:
                        y1='0'+str(y)
                    else: y1=str(y)
                    ti=x1+y1
                    if x1==y1:
                        col+=1
                    elif x1==y1[-1::-1]:
                        col+=1
                    elif int(ti[0])==int(ti[1])-1 and int(ti[1])==int(ti[2])-1 and int(ti[2])==int(ti[3])-1:
                        col+=1
                if x==h2 and y==m2:
                    break
        
        
elif h1>h2:
    for x in range(h1,h2+24+1):
        if x==h1:
            if x==h1:
            for y in range(m1,60):
                if x==h2 and y==m2:
                    break
                if x<10:
                    x1='0'+str(x)
                else: x1=str(x)
                if y < 10:
                    y1='0'+str(y)
                else: y1=str(y)
                ti=x1+y1
                if x1==y1:
                    col+=1
                elif x1==y1[-1::-1]:
                    col+=1
                elif int(ti[0])==int(ti[1])-1 and int(ti[1])==int(ti[2])-1 and int(ti[2])==int(ti[3])-1:
                    col+=1
        else:
            for y in range(0,60):
                if x>=24:
                    x=x-24
                if x==h2 and y==m2:
                    break
                if x<10:
                    x1='0'+str(x)
                else: x1=str(x)
                if y < 10:
                    y1='0'+str(y)
                else: y1=str(y)
                ti=x1+y1
                if x1==y1:
                    col+=1
                elif x1==y1[-1::-1]:
                    col+=1
                elif int(ti[0])==int(ti[1])-1 and int(ti[1])==int(ti[2])-1 and int(ti[2])==int(ti[3])-1:
                    col+=1
            if x==h2 and y==m2:
                break
            
print(col)