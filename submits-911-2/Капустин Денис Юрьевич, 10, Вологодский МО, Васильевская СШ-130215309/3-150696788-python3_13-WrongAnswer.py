x = int(input())
y = int(input())
z = int(input())
if x == y:
    print(-1)
else:
    a = x - 1
    b = 5 * z - 2 * x - y - a 
    if a == x or b == x or a >= y or b <= y or a < -10**9 or b > 10**9:
        a = 0
        b = 5 * z - 2 * x - y - a
        if b == x or b == y or a == y or b < -10**9 or b > 10**9:
           print(-1)
        else:
            print(a, x, y, x, b)           
    else:
        print(a, x, y, x, b)