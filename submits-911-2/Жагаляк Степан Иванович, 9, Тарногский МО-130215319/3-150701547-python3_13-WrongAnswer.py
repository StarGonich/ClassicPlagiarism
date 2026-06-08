x = int(input())
y = int(input())
z = int(input())

total = 5 * z
S = total - 2 * x - y

def solve():
    if x <= y:
        p = y + 1
        q = S - p
        if q < p:
            p, q = q, p
        if p < y or q < y or p == x or q == x or p == q:
            return -1
        return f"{x} {x} {y} {p} {q}"
    else:
        p = y - 1
        q = S - p
        if q > p:
            p, q = q, p
        if p > y or q > y or p == x or q == x or p == q:
            return -1
        return f"{p} {q} {y} {x} {x}"

result = solve()
if result == -1:
    if x <= y:
        p = y
        q = S - p
        if q >= y and q != x and p != x and p != q:
            print(x, x, y, p, q)
        else:
            print(-1)
    else:
        p = y
        q = S - p
        if q <= y and q != x and p != x and p != q:
            print(p, q, y, x, x)
        else:
            print(-1)
else:
    print(result)