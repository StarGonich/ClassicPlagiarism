n = int(input())
k = int(input())
for p in range(n + 1, n + k + 1):
    x = p * n
    x1 = 0
    while x % 2 == 0 and x % n == 0 and x % k == 0:
        x // 2
    while x % 3 == 0 and x % n == 0 and x % k == 0:
        x // 3
    while x % 5 == 0 and x % n == 0 and x % k == 0:
        x // 5
    if x > x1:
        x1 = x
print(x1)