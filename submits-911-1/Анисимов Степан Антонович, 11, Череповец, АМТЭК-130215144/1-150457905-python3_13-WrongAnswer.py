a=int(input())
b=int(input())
c=int(input())
d=int(input())
k=0
e=0
f=0
if a!=c:
    for j in range(60-b+1):
        e=a
        if b+j>59:
            if e+1>23:
                e=0
                f=0
            else:
                e+=1
                f=0
        else:
            f=b+j            
        if e==f:
            k+=1
            
        elif len(str(e))==1 and len(str(f))==1:
            if e==f:
                k+=1                
        elif len(str(e))==1 and len(str(f))==2:
            if str(f)==str(e)+'0':
                k+=1
            elif e==1 and int(str(e)[0])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                k+=1
        elif len(str(e))==2 and len(str(f))==1:
            if str(e)==str(f)+'0':
                k+=1
        elif len(str(e))==2 and len(str(f))==2:
            if str(e)==str(f)[1]+str(f)[0]:
                k+=1
            elif int(str(e)[0])+1==int(str(e)[1]) and int(str(e)[1])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                k+=1
else:
    if b>d:
        for j in range(b-d+1):
            e=a
            if b+j>59:
                if e+1>23:
                    e=0
                    f=0
                else:
                    e+=1
                    f=0
            else:
                f=b+j            
            if e==f:
                k+=1
                
            elif len(str(e))==1 and len(str(f))==1:
                if e==f:
                    k+=1                
            elif len(str(e))==1 and len(str(f))==2:
                if str(f)==str(e)+'0':
                    k+=1
                elif e==1 and int(str(e)[0])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                    k+=1
            elif len(str(e))==2 and len(str(f))==1:
                if str(e)==str(f)+'0':
                    k+=1
            elif len(str(e))==2 and len(str(f))==2:
                if str(e)==str(f)[1]+str(f)[0]:
                    k+=1
                elif int(str(e)[0])+1==int(str(e)[1]) and int(str(e)[1])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                    k+=1    
    elif d>b:
        for j in range(b-d+1):
            e=a
            if b+j>59:
                if e+1>23:
                    e=0
                    f=0
                else:
                    e+=1
                    f=0
            else:
                f=b+j            
            if e==f:
                k+=1
                
            elif len(str(e))==1 and len(str(f))==1:
                if e==f:
                    k+=1                
            elif len(str(e))==1 and len(str(f))==2:
                if str(f)==str(e)+'0':
                    k+=1
                elif e==1 and int(str(e)[0])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                    k+=1
            elif len(str(e))==2 and len(str(f))==1:
                if str(e)==str(f)+'0':
                    k+=1
            elif len(str(e))==2 and len(str(f))==2:
                if str(e)==str(f)[1]+str(f)[0]:
                    k+=1
                elif int(str(e)[0])+1==int(str(e)[1]) and int(str(e)[1])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                    k+=1        
if a-c>0:
    for i in range(1,a-c):
        for j in range(60):
                if a+i>23:
                    e=0
                else:
                    e=a+i
                if j>59:
                    if e+1>23:
                        e=0
                        f=0
                    else:
                        e+=1
                        f=0
                else:
                    f=b+j            
                if e==f:
                    k+=1
                elif len(str(e))==1 and len(str(f))==1:
                    if e==f:
                        k+=1                
                elif len(str(e))==1 and len(str(f))==2:
                    if str(f)==str(e)+'0':
                            k+=1
                    elif e==1 and int(str(e)[0])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                        k+=1
                elif len(str(e))==2 and len(str(f))==1:
                    if str(e)==str(f)+'0':
                        k+=1
                elif len(str(e))==2 and len(str(f))==2:
                    if str(e)==str(f)[1]+str(f)[0]:
                        k+=1
                    elif int(str(e)[0])+1==int(str(e)[1]) and int(str(e)[1])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                        k+=1       
    for j in range(d):
            e=c
            if j>59:
                if e+1>23:
                    e=0
                    f=0
                else:
                    e+=1
                    f=0
            else:
                f=j            
            if e==f:
                k+=1
            elif len(str(e))==1 and len(str(f))==1:
                if e==f:
                    k+=1                
            elif len(str(e))==1 and len(str(f))==2:
                if str(f)==str(e)+'0':
                    k+=1
                elif e==1 and int(str(e)[0])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                    k+=1
            elif len(str(e))==2 and len(str(f))==1:
                if str(e)==str(f)+'0':
                    k+=1
            elif len(str(e))==2 and len(str(f))==2:
                if str(e)==str(f)[1]+str(f)[0]:
                    k+=1
                elif int(str(e)[0])+1==int(str(e)[1]) and int(str(e)[1])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                    k+=1                                  
else:
    for i in range(1,c-a):
        for j in range(60):
                if a+i>23:
                    e=0
                else:
                    e=a+i
                if j>59:
                    if e+1>23:
                        e=0
                        f=0
                    else:
                        e+=1
                        f=0
                else:
                    f=j            
                if e==f:
                    k+=1
                elif len(str(e))==1 and len(str(f))==1:
                    if e==f:
                        k+=1                
                elif len(str(e))==1 and len(str(f))==2:
                    if str(f)==str(e)+'0':
                            k+=1
                    elif e==1 and int(str(e)[0])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                        k+=1
                elif len(str(e))==2 and len(str(f))==1:
                    if str(e)==str(f)+'0':
                        k+=1
                elif len(str(e))==2 and len(str(f))==2:
                    if str(e)==str(f)[1]+str(f)[0]:
                        k+=1
                    elif int(str(e)[0])+1==int(str(e)[1]) and int(str(e)[1])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                        k+=1
    for j in range(d):
            e=c
            if j>59:
                if e+1>23:
                    e=0
                    f=0
                else:
                    e+=1
                    f=0
            else:
                f=j            
            if e==f:
                k+=1
            elif len(str(e))==1 and len(str(f))==1:
                if e==f:
                    k+=1                
            elif len(str(e))==1 and len(str(f))==2:
                if str(f)==str(e)+'0':
                    k+=1
                elif e==1 and int(str(e)[0])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                    k+=1
            elif len(str(e))==2 and len(str(f))==1:
                if str(e)==str(f)+'0':
                    k+=1
            elif len(str(e))==2 and len(str(f))==2:
                if str(e)==str(f)[1]+str(f)[0]:
                    k+=1
                elif int(str(e)[0])+1==int(str(e)[1]) and int(str(e)[1])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                    k+=1
                    
            
print(k)