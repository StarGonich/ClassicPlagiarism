h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
if h1 == h2:
    for i in range(m1, m2+1):
        if h1 == i or ((h1 // 10 == i % 10) and (h1 % 10 == i // 10)) or ((h1 % 10 == h1 // 10 + 1) and (i // 10 == h1 % 10 + 1) and (i % 10 == i // 10 + 1)):
            k += 1
print(k)