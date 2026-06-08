h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
s = 0
while h1 != h2 or m1 != m2:
    if m1 == 60:
        h1 += 1
        m1 = 0
    if h1 == 24:
        h1 = 0
    if h1 == m1 or "0" * (2 - len(str(h1))) + str(h1) == ("0" * (2 - len(str(m1))) + str(m1))[::-1] or (h1 // 10 == h1 % 10 - 1 == m1 // 10 - 2 == m1 % 10 - 3):
        s += 1
    m1 += 1
print(s)
