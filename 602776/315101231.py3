##i = int(input())
a,b,p = map(int, input().split())
c,d,q = map(int, input().split())
##a*x+b*y=p
##c*x+d*y=q
##a*q/c-a*d*y/c+b*y=p
##y(b-a*d/c)=p-a*q/c
try:
    i = (p-a*q/c)
    o = (b-a*d/c)
    y = i/o
    x = (p-b*y)/a
    if x < 0 or y < 0:
        print("Not positive")
    else:
        print("Success")
        print(round(x*100,5),round(y*100,5))
except:
    if i > 0:
        print("Contradiction")
    elif i == 0:
        print("Ambiguity")