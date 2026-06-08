x = int(input())
y = int(input())
z = int(input())
s = 5*z - 2*x - y
if x < y:
    if s // 2 <= y:
        print(-1)
    else:
        if s % 2 != 0:
            print(x, x, y, s//2, s//2+1)
        else:
            print(x, x, y, s//2-1, s//2+1)
elif x > y:
    if s // 2 >= y:
        print(-1)
    else:
        if s % 2 != 0:
            print(s//2, s//2+1, y, x, x)
        else:
            print(s//2-1, s//2+1, y, x, x)  
else:
    if s//2 < x:
        if s % 2 != 0:
            print(s//2, s//2+1, y, x, x)
        else:
            print(s//2-1, s//2+1, y, x, x)  
    elif s // 2 > x:
        if s % 2 != 0:
            print(x, x, y, s//2, s//2+1)
        else:
            print(x, x, y, s//2-1, s//2+1)
    else:
        print(s//2-1, x, x, x, s//2+1)