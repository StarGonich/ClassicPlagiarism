h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
if h1 == h2 and m1 == m2:
    print('0')
else:
    s = ''
    count = 0
    for i in range(24):
        for j in range(60):
            s += str(i) + str(j) + ' '
    G1 = str(h1) + str(m1)
    G2 = str(h2) + str(m2)
    GG1 = s.find(G1)
    GG2 = s.find(G2)
    s = s[GG1:GG2:]
    s = s.split()
    print(s)
    for c in s:
        y = int(c)
        if y // 100 < 10:
            i1 = y // 10
            i2 = y % 10
        if y // 100 > 10:
            i1 = y // 100
            i2 = y % 100
        j = str(i2)[::-1]
        print(i1,i2)
        if i1 == i2:
            count += 1
        if i1 == int(j):
            count += 1
        if c in '0123456789':
            count += 1
        print(count)