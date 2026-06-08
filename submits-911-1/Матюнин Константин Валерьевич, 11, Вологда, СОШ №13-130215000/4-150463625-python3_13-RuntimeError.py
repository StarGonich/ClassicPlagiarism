n = int(input())
k = int(input())

b = []

for i in range(100000):
    if n+1 <= i <= n+k:
        for j in range(3, i):
            if n % j == 0 and i % j == 0:
                b.append(i)
                break

print(max(b))