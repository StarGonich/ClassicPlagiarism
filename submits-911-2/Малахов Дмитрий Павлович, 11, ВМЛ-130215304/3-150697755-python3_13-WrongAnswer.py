x = int(input())
y = int(input())
z = int(input())

z = z * 5
z = z - 2 * x - y
if z % 2 == 0:
    minh = z // 2 - 1
    maxh = minh + 2
else:
    minh = z // 2
    maxh = minh + 1

if x < y:
    if minh > y:
        print(x, x, y, minh, maxh)
    else:
        print(-1)
else:
    if maxh < y:
        print(minh, maxh, y, x, x)
    else:
        print(-1)