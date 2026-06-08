h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
a = 0
if h1 == h2 and m1 == m2:
    print(0)
else:
    while h1 != h2 and m1 != m2:
        for i in range(h1, h2):
            for j in range(m1, 59):
                 if j == i:
                     a += 1
print(a)