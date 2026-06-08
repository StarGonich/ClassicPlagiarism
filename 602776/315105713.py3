a, b, p = map(int, input().split())
c, d, q = map(int, input().split())

if (a*d - b*c) == 0:
    r = 0
    if(c != 0):
        r = a/c
    elif(d!=0):
        r = b/d
    if r == p/q:
        print("Ambiguity")
    else:
        print("Contradiction")
else:
    if(a != 0):
        y = (q-c*p/a)/(d-c*b/a)
        x = (p - b*y)/a
    else:
        y = p/b
        x = (q - d*y)/c
    if ((x > 0) and (y > 0)):
        print("Success")
        print(x*100, y*100)
    else:
        print("Not positive")