x = int(input())
y = int(input())
z = int(input())
s = 5*z
if x<y:
    if 2*x+3*y+3 > s:
        print('-1')
    else:
        print(x, x, y, y+1, (s-2*x-2*y-1))
if x>y:
    if 2*x+3*y-3 < s:
        print('-1')
    else:
        print((s-2*y-2*x-1),y-1, y, x, x)
if x == y:
    if y > 0:
        if 2*y>=s:
            print(s-3*y-1, 0, y, y, y+1)
        if 2*y<s:
            print(-1, 0, y, y, s-2*y+1)
    if y == 0:
        print (-2, -1, 0, 0, 3)
    if y < 0:
        if s >= 2*y:
            print(y-1, y, y, 0, s-3*y+1)
        elif s < 2*y:
            print(s-4*y, y-1, y, y, y+1)