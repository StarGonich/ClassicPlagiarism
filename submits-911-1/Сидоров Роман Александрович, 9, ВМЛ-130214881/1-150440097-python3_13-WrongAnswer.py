h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
t1 = h1 * 60 + m1
t2 = h2 * 60 + m2
n = 0
if (t1 <= t2):
    for i in range(t2 - t1 + 1):
        h11 = h1 + (i // 60)
        m11 = m1 + (i % 60)
        if h11 == m11:
            n = n + 1
        if h11 == ((m11 // 10) + 10 * (m11 % 10)):
            n = n + 1
        if ((h11 % 10) - (h11 // 10) == 1) and ((m11 // 10) - (h11 % 10) == 1) and ((m11 % 10) - (m11 // 10) == 1):
            n = n + 1
else:
    for i in range(t2 - t1 + 24 * 60 + 1):
        h11 = h1 + (i // 60)
        m11 = m1 + (i % 60)
        if h11 >= 24:
            h11 = h11 - 24
        if h11 == m11:
            n = n + 1
        if h11 == ((m11 // 10) + 10 * (m11 % 10)):
            n = n + 1
        if ((h11 % 10) - (h11 // 10) == 1) and ((m11 // 10) - (h11 % 10) == 1) and ((m11 % 10) - (m11 // 10) == 1):
            n = n + 1
print(n)