n = int(input())
a = [1] * 30
a[1] = 2
a[2] = 3
k = 0
for i in range(3, 30):
    a[i] = 2 * a[i - 1]
for i in range(n):
    k += a[i]
print(k)
for i in range(n):
    print(a[i], end = ' ')