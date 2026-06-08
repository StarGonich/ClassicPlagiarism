h1 = int(input())
m1 = int(input()) + h1 * 60
h2 = int(input())
m2 = int(input()) + h2 * 60
k = 0
if m2 < m1:
    n = 1440 - m1
    for i in range(n):
        h = (i+m1) // 60
        m = (i+m1) - h * 60
        if h == m:
            k += 1
        elif h // 10 == m % 10 and h % 10 == m // 10:
            k += 1
        elif h // 10 == (h % 10) - 1 == (m // 10) - 2 == (m % 10) - 3:
            k += 1
    for i in range(m2 + 1):
        h = i // 60
        m = i - h * 60
        if h == m:
            k += 1
        elif h // 10 == m % 10 and h % 10 == m // 10:
            k += 1
        elif h // 10 == (h % 10) - 1 == (m // 10) - 2 == (m % 10) - 3:
            k += 1        
else:
    n = m2 - m1
    for i in range(n + 1):
        h = (i + m1) // 60
        m = (i + m1) - h * 60
        if h == m:
            k += 1
        elif h // 10 == m % 10 and h % 10 == m // 10:
            k += 1
        elif h // 10 == (h % 10) - 1 == (m // 10) - 2 == (m % 10) - 3:
            k += 1
print(k)