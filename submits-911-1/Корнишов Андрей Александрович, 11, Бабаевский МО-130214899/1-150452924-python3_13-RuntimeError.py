h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
c = 0
h = h1
m = m1
while h != ch2 and m != m2:
    if h == m:
        c += 1
    m += 1
    if m > 59:
        h += 1
    elif h > 23:
        h = 0