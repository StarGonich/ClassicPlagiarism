n = int(input())

s = n * (n + 1) // 2

for i in range(1, n + 1):
    if s % i != 0:
        print(-1)
        exit()

print(s)
print(*range(1, n + 1))