x = int(input())
y = int(input())
z = int(input())

total = 5 * z

if x == y:
    d = x + 1
    e = total - 3 * x - d
    if e >= x and e != x:
        print(x, x, x, d, e)
        exit()
    d = x + 100
    e = total - 3 * x - d
    if e >= x and e != x:
        print(x, x, x, d, e)
        exit()
    d = (total - 3 * x) // 2
    e = d
    if d >= x and (total - 3*x - d - e) == 0 and d != x:
        print(x, x, x, d, e)
        exit()

if x != y:
    if x > y:
        print(-1)
        exit()
    d = y + 1
    e = total - 2*x - y - d
    if e >= y and e != x and d != x:
        print(x, x, y, d, e)
        exit()
    d = y + 100
    e = total - 2*x - y - d
    if e >= y and e != x and d != x:
        print(x, x, y, d, e)
        exit()
    rem = total - 2*x - y
    if rem % 2 == 0:
        d = rem // 2
        e = d
        if d >= y and d != x:
            print(x, x, y, d, e)
            exit()

print(-1)