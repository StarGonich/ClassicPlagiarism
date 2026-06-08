h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
if h1 == h2:
    for i in range(m1, m2 + 1):
        if h1 == i or ((h1 // 10 == i % 10) and (h1 % 10 == i // 10)) or ((h1 % 10 == h1 // 10 + 1) and (i // 10 == h1 % 10 + 1) and (i % 10 == i // 10 + 1)):
            k += 1
else:
    for i in range(h1 + 1, h2):
        if (i >= 1 and i <= 4) or (i >= 12 and i <= 14) or (i == 23):
            k = k + 3
        if (i == 5) or (i==10) or (i == 15) or (i>=20 and i <=21):
            k = k + 2
        if (i >= 6 and i <= 9) or (i >= 16 and i <= 19) or (i == 22) or (i == 0) or (i == 11):
            k = k + 1
    for i in range(m1, 60):
        if h1 == i or ((h1 // 10 == i % 10) and (h1 % 10 == i // 10)) or ((h1 % 10 == h1 // 10 + 1) and (i // 10 == h1 % 10 + 1) and (i % 10 == i // 10 + 1)):
            k += 1
    for i in range(0, m2 + 1):
        if h2 == i or ((h2 // 10 == i % 10) and (h2 % 10 == i // 10)) or ((h2 % 10 == h2 // 10 + 1) and (i // 10 == h2 % 10 + 1) and (i % 10 == i // 10 + 1)):
            k += 1
print(k)