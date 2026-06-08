h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
h3 = h1
while h2 - h1 >= 0:
    if h2 - h1 >= 0:
        if h1 == m2 - m1:
            k += 1

        if h1 < m2 - m1:
            k += 1

        if str(h3) == str((m2-m1) % 10) + str((m2-m1) % 100) and  m2 - m1 > m1:
            k += 1
        if str(h2) == str((m2 - m1) % 10) + str((m2 - m1) % 100) and m2 - m1 > m1:
            k += 1
        if h1 < 60:
            k += 1
    h1 += 1
print(k)
if h1 == h2 and m1 == m2:
    print(0)
if h1 == h2 and m1 == m2:
    print(0)
if h1 == h2 and m2-m1>h1:
    print(2)
if h1 - h2 == 1 and m2-m1>h1:
    print(4)

