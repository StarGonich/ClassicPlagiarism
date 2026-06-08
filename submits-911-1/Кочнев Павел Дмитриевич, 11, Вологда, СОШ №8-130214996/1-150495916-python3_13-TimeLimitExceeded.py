h1, m1, h2, m2 = int(input()), int(input()), int(input()), int(input())
count = 0
while ((h1 != h2) or (m1 != m2)):
    if m1 < 60:
        if (h1 == m1) or (h1 // 10 * 10 + h1 % 10 == m1 % 10 * 10 + m1 // 10) or (h1 // 10 == h1 % 10 - 1 == m1 // 10 - 2 == m1 % 10 - 3):
            count += 1
        m1 += 1
    elif m1 == 60:
        m1 = 0
        h1 += 1
print(count)