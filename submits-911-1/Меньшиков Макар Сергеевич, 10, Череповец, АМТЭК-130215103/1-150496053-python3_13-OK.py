h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
if h1 == h2 and m1 > m2:
    while m2 <= m1:
        h = str(h2)
        m = str(m2)
        if h2 == m2:
            k += 1
        elif int(h[::-1]) == m2 or int(m[::-1]) == h2:
            k += 1
        elif h2 // 10 == h2 % 10 - 1 and h2 // 10 == m2 // 10 - 2 and h2 // 10 == m2 % 10 - 3:
            k += 1
        m2 += 1
    k = 40 - k
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
print(k)


