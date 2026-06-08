h = []
s = []
n = int(input())
k = int(input())





for p in range(n + 1, n + k + 1):
    a = n
    b = p
    
    while a != b:
        if b > a:
            b = b - a
        else:
            a = a - b
    if a != 1:
        h.append(a)
    s.append(n * p // a)

print((min(s) * max(h)) // n)