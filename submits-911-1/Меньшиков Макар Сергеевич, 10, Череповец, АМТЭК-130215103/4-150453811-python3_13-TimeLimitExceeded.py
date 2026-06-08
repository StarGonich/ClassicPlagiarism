def MN(x, y):
    for i in range(1, x * y + 1, 1):
        if i % x == 0 and i % y == 0:
            return i


n = int(input())
k = int(input())
mn = 99999999
p = 0
for i in range(n + 1, n + k + 1, 1):
    if mn >= MN(i, n):
        mn = MN(i, n)
        p = i
print(p)
