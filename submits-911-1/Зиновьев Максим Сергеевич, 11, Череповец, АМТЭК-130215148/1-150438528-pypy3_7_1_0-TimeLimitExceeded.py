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
    h1 = int(h1)
    m1 = int(m1)
    if (m1 - h1) == 22:
        k += 1
    if h1 == h2 and m1 == m2:
        break
    m1 = m1 + 1
    if m1 == 60:
        h1 += 1
        m1 = 0
print(k)