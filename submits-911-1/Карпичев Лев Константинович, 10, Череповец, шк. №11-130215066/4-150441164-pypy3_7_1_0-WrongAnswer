n = int(input())
k = int(input())
i2 = 0
p2 = 0
for p in range(n + 1, n + k + 1):
    for i in range(1, p * n + 1):
        if i % p == 0 and i % n == 0:
            if i2 == 0:
                i2 = i
            elif i < i2:
                i2 = i
                p2 = p
print(p2)