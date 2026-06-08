h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
if h2 >= h1 and m2 >= m1:
    z = (h2 - h1) * 60 + (m2 - m1)
elif h2 < h1 and m2 > m1:
    z = (h2 + 24 - h1) * 60 + (m2 - m1)
elif h2 <= h1 and m2 < m1:
    z = (h2 + 23 - h1) * 60 + (m2 + 60 - m1)
elif h2 > h1 and m2 < m1:
    z = (h2 - h1 - 1) * 60 + (m2 + 60 - m1)
print(z)
if z == 0:
    z += 1
for i in range(z+1):
    a = h1 // 10
    b = h1 % 10
    c = m1 // 10
    d = m1 % 10
    print(a, b, c, d)
    if ((a == c) and (b == d)) or ((a == d) and (b == c)) or ((a + 1 == b) and (b + 1 == c) and (c + 1 == d)):
        ##print(a, b, c, d, ' ')
        k += 1
    if m1 + 1 < 60:
        m1 += 1
    else:
        m1 = 0
        h1 += 1
    if h1 == 24:
        h1 = 0
print(k)
        