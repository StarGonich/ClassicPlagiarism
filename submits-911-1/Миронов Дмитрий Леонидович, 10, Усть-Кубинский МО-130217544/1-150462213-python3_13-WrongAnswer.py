a1 = int(input())
b1 = int(input())
a2 = int(input())
b2 = int(input())
c = 0
z=0
if a1 == a2 and b1 == b2:
    print(0)
else:
    for i in range(b1,61):
        if a1 == i:
            c +=1
    if a2-a1 == 1:
        for i in range(b1,61):
            if a1 == i:
                c +=1
        for i in range(0,b2+1):
            if a1 == i:
                c +=1
    else:
        for i in range(b1,61):
            if a1 == i:
                c +=1
        for i in range(a2-a1-1):
            for i in range(0,61):
                if a1 == i:
                    c += 1
            z +=1
            for i in range(0, b2+1):
                if a1 == i:
                    c += 1
    print(c)