n = int(input())
k = int(input())
for p in range(n + 1, n + k + 1):
    x = p * n
    x1 = 0
    while x1 % n != 0 and x1 % k != 0:
        x1 += p
        p += 1
print(x1)