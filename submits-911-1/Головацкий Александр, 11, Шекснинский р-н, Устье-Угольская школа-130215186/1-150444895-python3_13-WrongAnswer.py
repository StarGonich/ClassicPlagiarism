h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
c = 0 
for h in range(h1, h2+1):
    for m in range(m1, m2+1):
        if h == m:
            c += 1
        if m % 10 == h // 10 and m // 10 == h % 10:
            c += 1
        if (h // 10) + 1== h % 10 and (h % 10) + 1 == m // 10 and (m // 10) + 1 == m % 10:
            c += 1
print(c)