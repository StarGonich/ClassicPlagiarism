h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
if h1 == h2 and m1 > m2:
    l = 0
    u = h1
    y = h2
    h2 -= 1
while h1 != h2:
    h = str(h1)
    m = str(m1)
    if h1 == m1:
        k += 1
    elif int(str(h1)[::-1]) == m1 or int(str(m1)[::-1]) == h1:
        k += 1
    elif h1 // 10 == h1 % 10 - 1 and h1 // 10 == m1 // 10 - 2 and h1 // 10 == m1 % 10 - 3:
        k += 1
    m1 += 1
    if m1 == 60:
        m1 = 0
        h1 += 1
        if h1 == 24:
            h1 = 0
while m1 <= m2:
    h = str(h1)
    m = str(m1)
    if h1 == m1:
        k += 1
    elif int(h[::-1]) == m1 or int(m[::-1]) == h1:
        k += 1
    elif h1 // 10 == h1 % 10 - 1 and h1 // 10 == m1 // 10 - 2 and h1 // 10 == m1 % 10 - 3:
        k += 1
    m1 += 1
if y == u:
    while h1 != u:
        h = str(h1)
        m = str(m1)
        if h1 == m1:
            k += 1
        elif int(str(h1)[::-1]) == m1 or int(str(m1)[::-1]) == h1:
            k += 1
        elif h1 // 10 == h1 % 10 - 1 and h1 // 10 == m1 // 10 - 2 and h1 // 10 == m1 % 10 - 3:
            k += 1
        m1 += 1
        if m1 == 60:
            m1 = 0
            h1 += 1
            if h1 == 24:
                h1 = 0
    while m1 <= m2:
        h = str(h1)
        m = str(m1)
        if h1 == m1:
            k += 1
        elif int(h[::-1]) == m1 or int(m[::-1]) == h1:
            k += 1
        elif h1 // 10 == h1 % 10 - 1 and h1 // 10 == m1 // 10 - 2 and h1 // 10 == m1 % 10 - 3:
            k += 1
        m1 += 1
print(k)



