h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
while True:
    h1 = str(h1)
    m1 = str(m1)
    if len(h1) == 1:
        h1 = '0' + h1
    if len(m1) == 1:
        m1 = '0' + m1
    if h1 == m1:
        k += 1
    if h1 == m1[::-1]:
        k += 1
    x1 = h1[0]
    x2 = h1[1]
    x3 = m1[0]
    x4 = m1[1]
    if (int(x1) + 1) == int(x2) and (int(x2) + 1) == int(x3) and (int(x3) + 1) == int(x4):
        k += 1
    h1 = int(h1)
    m1 = int(m1)
    if h1 == h2 and m1 == m2:
        break
    m1 = m1 + 1
    if m1 == 60:
        h1 += 1
        m1 = 0
print(k)