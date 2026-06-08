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
    for j in range(h1, h2):
        for i in range(m1, 60):
            if j == i or ((j // 10 == i % 10) and (j % 10 == i // 10)) or ((j % 10 == j // 10 + 1) and (i // 10 == j % 10 + 1) and (i % 10 == i // 10 + 1)):
                k += 1
    for i in range(0, m2 + 1):
        if h2 == i or ((h2 // 10 == i % 10) and (h2 % 10 == i // 10)) or ((h2 % 10 == h2 // 10 + 1) and (i // 10 == h2 % 10 + 1) and (i % 10 == i // 10 + 1)):
            k += 1
print(k)