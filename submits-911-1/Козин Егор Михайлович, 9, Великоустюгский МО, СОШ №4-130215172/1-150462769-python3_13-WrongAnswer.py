h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
x=0
hoursinminute1=h1*60+m1
hoursinminute2=h2*60+m2
colvo=hoursinminute2-hoursinminute1
if hoursinminute1==hoursinminute2:
    print(1)
for i in range(colvo):
    if h1==m1*10 or h1==m1:
        x+=1
    elif m1%10-h1==2:
        x+=1
    m1+=1
    if m1==59:
        m1-59
        h1+=1
    if h1==24:
        h1-24
print(x)