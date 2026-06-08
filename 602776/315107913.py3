##i = int(input())
a,b,p = map(int, input().split())
c,d,q = map(int, input().split())
def pneg(x, y):
    if x < 0 or y < 0:
        print("Not positive")
    else:
        print("Success")
        print(round(x*100,5),round(y*100,5))
##a*x+b*y=p
##c*x+d*y=q
##a*q/c-a*d*y/c+b*y=p
##y(b-a*d/c)=p-a*q/c
try:
    if a == c == 0:
        if b/p==d/q:
            print("Ambiguity")
        else:
            print("Contradiction")
        exit()
    if b == d == 0:
        if a/p==c/q:
            print("Ambiguity")
        else:
            print("Contradiction")
        exit()
    if a == 0 and d == 0:
        y = p / b
        x = q / c
        pneg(x,y)
        exit()
    if b == 0 and c == 0:
        x = p / a
        y = q / d
        pneg(x,y)
        exit()
    if a == 0:
        y = p / b
        x = (q-d*y)/c
        pneg(x,y)
        exit()
    if b == 0:
        x = p / a
        y = (q - c*x)/d
        pneg(x,y)
        exit()
    if c == 0:
        y = q / d
        x = (p-b*y)/a
        pneg(x,y)
        exit()
    if d == 0:
        x = q / c
        y = (p - a*x)/b
        pneg(x,y)
        exit()
    
    i = (p-a*q/c)
    o = (b-a*d/c)
    y = i/o
    x = (p-b*y)/a
    pneg(x,y)
except ZeroDivisionError:
    if i > 0:
        print("Contradiction")
    elif i == 0:
        print("Ambiguity")
##b = list(map(int, input().split()))
##for t in range(int(input())):
##    pass
##s = input()
