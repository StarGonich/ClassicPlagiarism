h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
h, m = h1, m1
while True:
    a = h // 10
    b = h % 10
    c = m // 10
    d = m % 10
    if h == m or a*10+b == d *10+c:
        k += 1
    if h == h2 and m == m2:
        break
    m += 1
    if m > 59:
        m = 0
        h += 1
print(k)