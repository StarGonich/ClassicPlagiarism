h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
while h1 != h2:
    while m1 != 60:
        if (h1 == m1) or (h1 == m1 % 10 * 10 + m1 // 10) or (h1 // 10 == h1 % 10 - 1 and h1 % 10 == m1 // 10 - 1 and m1 // 10 == m1 % 10 - 1):
            k += 1
        m1 += 1
    h1 += 1
    m1 = 0
for i in range(m2):
    if (h1 == m1) or (h1 == m1 % 10 * 10 + m1 // 10) or (h1 // 10 == h1 % 10 - 1 and h1 % 10 == m1 // 10 - 1 and m1 // 10 == m1 % 10 - 1):
        k += 1
    m1 += 1
print(k)