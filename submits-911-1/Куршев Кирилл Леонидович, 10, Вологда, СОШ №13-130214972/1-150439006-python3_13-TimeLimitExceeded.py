h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
y = 0
if h1 != h2:
    while h1 != h2:
        while m1 != m2:
            if h1 == m1:
                y += 1
            if (m1 // 10 == h1+1) and (m1 % 10 == h1+2):
                y += 1
            if h1 < 10:
                if m1 * 10 == h1:
                    y += 1
            if h1 >= 10:
                if (m1 // 10 == h1 % 10) and (m1 % 10 == h1 // 10):
                    y += 1
            m1 += 1
    h1 += 1
    print (y)
if h1 == h2:
    while m1 != m2:
        if h1 == m1:
            y += 1
        if (m1 // 10 == h1 + 1) and (m1 % 10 == h1 + 2):
            y += 1
        if h1 < 10:
            if m1 * 10 == h1:
                y += 1
        if h1 >= 10:
            if (m1 // 10 == h1 % 10) and (m1 % 10 == h1 // 10):
                y += 1
        m1 += 1
h1 += 1
print(y)