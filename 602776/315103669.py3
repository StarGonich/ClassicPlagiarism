b = int(input())
k = 0
for i in range(0, b+1, 4):
    if (i % 20 != 0) and (i % 30 != 0) and (i % 12 != 0):
        k += 1
for i in range(0, b+1, 5):
    if (i % 20 != 0) and (i % 30 != 0) and (i % 12 != 0):
        k += 1
for i in range(0, b+1, 6):
    if (i % 20 != 0) and (i % 30 != 0) and (i % 12 != 0):
        k += 1
print(k)