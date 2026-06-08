x=int(input())
y=int(input())
z=int(input())
j=""
m=""
for i1 in range(10):
    for i2 in range(10):
        for i3 in range(10):
            for i4 in range(10):
                for i5 in range(10):
                    f=[i1,i2,i3,i4,i5]
                    f.sort()
                    if f[2]==y:
                        if len(set(f))==4:
                            seen=set()
                            dup=set()
                            for i in f:
                                if i in seen:
                                    dup.add(i)
                                else:seen.add(i)
                            if sum(dup)/len(dup)==x:
                                while j=="":
                                    if sum(f)/5==z:
                                        j=f
                                        if sum(f)>-1:
                                            m=(i1,i2,i3,i4,i5)
                                            print(m)
                                        else:
                                            print(-1)
                                            break


   