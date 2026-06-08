h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
n1 = ['00', '01', '02', '03', '04', '05', '06', '07', '08', '09'] + [str(x) for x in range(10,61)]
if h1 == h2 and m1 == m2:
    print(0)
else:
    if h1 != h2:
        I = h2 - h1 - 2
    else:
        I = h2 - h1
    if h1 >= m1:
        I += 1
    if h2 >= m2:
        I += 1

    II = 0
    m4 = m1
    for h in range(h1, h2+1):
        if h2 - h == 0:
            m3 = m2
        else:
            m3 = 60
        if str(h)[::-1] in n1[m4:m3+1]:
            II += 1
            continue
        m4 = 0

    III = 0
    for i in range(h1, h2+1):
        if i == 23:
            if m2 >= 45:
                III += 1
        if i == 12:
            if h2 > 12:
                III += 1
            else:
                if m2 >= 34:
                    III += 1
        if i == 1:
            if h2 > 1:
                III += 1
            else:
                if m2 >= 24:
                    III += 1
    print(I+II+III)