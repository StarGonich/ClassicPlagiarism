b = int(input())
k = 0
for i in range(0, b+1):
    if (i == 0): continue
    if (i % 4 == 0) ^ (i % 5 == 0) ^ (i % 6 == 0):
        k += 1
print(k)