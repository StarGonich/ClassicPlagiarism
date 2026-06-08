x = int(input())
y = int(input())
z = int(input())
s = 5 * z
if x < y:
    if 2*x + 3*y + 3 > s:
        print('-1')
    else:
        print(x, x, y, y + 1, (s-(2*x+2*y+1)))
elif x > y:
    if 2*x + 3*y - 3 < s:
        print('-1')
    else:
        print((s - (2*y+2*x-1)), y - 1, y, x, x)
else:
    if 2 * y > s:
        print(s - 4*y, y-1, y, y, y + 1)
    elif 2 * y < s:
        print(y-2, y-1, y, y, s -(4*y-3))
    else:
        print(y*(-1), 0, y, y, y)