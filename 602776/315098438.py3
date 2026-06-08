b = int(input())
k = 0
for i in range(1, b+1):
    n = 0
    if i % 4 == 0:
        n += 1
    if i % 5 == 0:
        n += 1
    if i % 6 == 0:
        n += 1
    if n == 1:
        k += 1
print(k)