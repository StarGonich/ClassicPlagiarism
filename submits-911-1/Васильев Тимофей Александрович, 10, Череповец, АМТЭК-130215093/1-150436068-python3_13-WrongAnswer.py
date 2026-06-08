h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
while h1 <= h2 and m1 <= m2:
    if m1 == 60:
        m1 = 0
        h1 += 1
    if h1 == m1:
        k += 1
    if h1 // 10 == m1 % 10 and h1 % 10 == m1 // 10:
        k += 1
    if h1 // 10 == h1 % 10 - 1 == m1 // 10 - 2 == m1 % 10 - 3:
        k += 1
    m1+=1
print(k)