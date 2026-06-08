h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
x=h1*60+m1
y=h2*60+m2
n=y-x+1
if h1<10:
    h='0'+str(h1)
else:
    h=str(h1)
if m1<10:
    m='0'+str(m1)
else:
    m=str(m1)
k=0
for i in range(n):
    if h==m:
        k+=1
    elif h==m[::-1]:
        k+=1
    elif int(h[1])==int(h[0])+1 and int(m[0])==int(h[1])+1 and int(m[1])==int(m[0])+1:
        k+=1
    m=str(int(m)+1)
    if int(m)<10:
        m='0'+m
    if m=='60':
        h=str(int(h)+1)
        if int(h)<10:
            h='0'+h
        m='00'
print(k)