a=int(input())
b=int(input())
c=int(input())
d=int(input())
k=0
e=0
f=0
if a-c>0:
    for i in range(a-c+1):
        if b-d>=0:
            for j in range(b-d+1):
                if a+i>23:
                    e=0
                else:
                    e=a+i
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
                elif len(str(e))==1 and len(str(f))==2:
                    if str(f)==str(e)+'0':
                            k+=1
                    elif e==1 and int(str(e)[0])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                        k+=1
                elif len(str(e))==2 and len(str(f))==1:
                    if str(e)==str(f)+'0':
                        k+=1
                elif int(str(e)[0])+1==int(str(e)[1]) and int(str(e)[1])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                    k+=1
        else:
            for j in range(d-b+1):
                if a+i>23:
                    e=0
                else:
                    e=a+i
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
                elif len(str(e))==1 and len(str(f))==2:
                    if str(f)==str(e)+'0':
                            k+=1
                    elif e==1 and int(str(e)[0])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                        k+=1
                elif len(str(e))==2 and len(str(f))==1:
                    if str(e)==str(f)+'0':
                        k+=1
                elif int(str(e)[0])+1==int(str(e)[1]) and int(str(e)[1])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                    k+=1
else:
    for i in range(c-a+1):
        if b-d>=0:
            for j in range(b-d+1):
                if a+i>23:
                    e=0
                else:
                    e=a+i
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
                elif len(str(e))==1 and len(str(f))==2:
                    if str(f)==str(e)+'0':
                            k+=1
                    elif e==1 and int(str(e)[0])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                        k+=1
                elif len(str(e))==2 and len(str(f))==1:
                    if str(e)==str(f)+'0':
                        k+=1
                elif int(str(e)[0])+1==int(str(e)[1]) and int(str(e)[1])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                    k+=1                
        else:
            for j in range(d-b+1):
                if a+i>23:
                    e=0
                else:
                    e=a+i
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
                elif len(str(e))==1 and len(str(f))==2:
                    if str(f)==str(e)+'0':
                            k+=1
                    elif e==1 and int(str(e)[0])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                        k+=1
                elif len(str(e))==2 and len(str(f))==1:
                    if str(e)==str(f)+'0':
                        k+=1
                elif int(str(e)[0])+1==int(str(e)[1]) and int(str(e)[1])+1==int(str(f)[0]) and int(str(f)[0])+1==int(str(f)[1]):
                    k+=1
print(k)