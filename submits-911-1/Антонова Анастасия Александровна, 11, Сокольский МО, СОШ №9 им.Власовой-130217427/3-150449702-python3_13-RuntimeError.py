n1=int(input())
n=[]
if 1<=n1<=30:
    for m in range(0,100):
        for x in range(0,100):
            if m%x==0:
                n.append(x)
print (n)