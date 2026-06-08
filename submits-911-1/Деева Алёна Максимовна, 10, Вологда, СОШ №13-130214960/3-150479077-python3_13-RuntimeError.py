N = int(input())
T = int(input())
i=0
a=-1
b=0
while i<N:
    t1 = int(input())
    t2 = int(input())
    if t2-t1+b>1000:
        if t2-3599>a:
            a=t2-3599 - (t2-t1+b-1000)
    b=t2-t1
    i=i+1
    tt1=t1
    tt2=t2
print (a)