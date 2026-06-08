h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())

count=0

 
x=0 #количество часов

y=0 #количество минут 


def abc(x,y):
    if len(x)==1:
        x="0"+x
    if len(y)==1:
        y="0"+y
    #print(x,":",y)
        
    #print("++++++++++++++++++++++")
    #print(x,y)
    #print(x,y[::-1])
    #print(x[0],x[1],y[0],y[1])
    #print(x==y)
    #print(x==(y[::-1]))
    #print(int(x[0])+1==int(x[1]) and int(x[1])+1==int(y[0]) and int(y[0])+1==int(y[1]))
    if (x==y) or (x==(y[::-1])) or (int(x[0])+1==int(x[1]) and int(x[1])+1==int(y[0]) and int(y[0])+1==int(y[1])):
        return True
    else:
        return False


if h1==h2:
    if m1==m2:
        
        x=str(h1)
        y=str(m1)
        if abc(x,y):
            count+=1
        
    else:
        for i in range(m2-m1+1):
            
            x=str(h1)
            y=str(i+m1)
            if abc(x,y):
                count+=1
                
                
else:
    for i in range(h2-h1+1):
        
        if i==0:
            for j in range(60-m1):
                x=str(i+h1)
                y=str(j+m1)
                if abc(x,y):
                    count+=1
                        
        else:
            if i==(h2-h1):
                for j in range(m2+1):
                    x=str(h2)
                    y=str(j)
                    if abc(x,y):
                        count+=1            
            else:
                for j in range(60):
                    x=str(i+h1)
                    y=str(j)
                    
                    if abc(x,y):
                        count+=1

print(count)