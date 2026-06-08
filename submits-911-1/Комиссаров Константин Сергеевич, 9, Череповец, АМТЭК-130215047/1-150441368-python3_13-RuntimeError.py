h1, m1, h2, m2 = map(int, input().split())
h11 = h1
m11 = m1
k = 0
i = 0
s = 0
while (h11 != h2 or m11 != m2) or s == 0:
    s += 1
    if s != 1:
        m11 += 1
    if m11 % 60 == 0 and m11 != 0:
        h11 += 1
        m11 = 0
    if h11 % 24 == 0:
        h11 = 0    
    strm11 = str(m11)
    strh11 = str(h11)
    if m11 < 10:
        strm11 = '0' + str(m11)
    if h11 < 10:
        strh11 = '0' + str(h11)
    if (m11 == h11):
        k += 1
    elif strh11[::-1] == strm11:
        k += 1
    elif (h11 % 10 + 1 == h11 // 10) and (m11 // 10 + 1 == h11 % 10) and (m11 % 10 + 1 == m11 // 10):
        k += 1
print(k)