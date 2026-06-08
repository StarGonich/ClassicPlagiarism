b = int(input())
k = 0
for i in range(1, b+1):
    i -= 1
    if (i % 4 == 0) ^ (i % 5 == 0) ^ (i % 6 == 0):
        k += 1
print(k)