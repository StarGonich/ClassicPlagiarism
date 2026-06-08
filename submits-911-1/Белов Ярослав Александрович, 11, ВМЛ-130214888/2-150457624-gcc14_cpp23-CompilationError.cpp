n = int(input())
if (n == 1):
    print(1)
    exit(0)
if (n == 2):
    print(-1)
    exit(0)
x = 3 * 2 ** (n - 2)
print(x)
print(1, 2, 3, end=' ')
y = 6
for i in range(n - 3):
    print(y, end=' ')
    y *= 2
