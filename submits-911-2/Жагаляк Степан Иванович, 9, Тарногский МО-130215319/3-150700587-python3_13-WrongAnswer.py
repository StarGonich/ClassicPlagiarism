x = int(input())
y = int(input())
z = int(input())
total = 5 * z
S = total - 2 * x - y
if x <= y:
    p = y
    q = S - p
    if q < y:
        dif = y - q
        p += dif
        q = S - p
    if p < y or q < y or p == x or q == x or p == q:
        print(-1)
    else:
        a, b, c, d, e = sorted([x, x, y, p, q])
        print(x, x, y, p, q)
else: 
    p = y
    q = S - p
    if q > y:
        diff = q - y
        p -= diff
        q = S - p
    if p > y or q > y or p == x or q == x or p == q:
        print(-1)
    else:
        a, b, c, d, e = sorted([x, x, y, p, q])
        print(p, q, y, x, x)
