h = int(input())
m = int(input())
c = int(input())
n = int(input())
k = 0
while (h != c) or (m != n):
    if m == 60:
        m = 0
        h = h + 1
    if h == 24:
        h = 0
    if h == m:
        k = k + 1
    elif (h % 10 == m // 10) and (h // 10 == m % 10):
        k = k + 1
    elif (h / 10 == h % 10 + 1) and (h % 10 == m // 10 + 1) and (m // 10 == m % 10 + 1):
        k = k + 1
    m = m + 1
print(k)