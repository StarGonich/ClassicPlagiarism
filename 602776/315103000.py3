b = int(input())
k = 0
for i in range(0, b+1):
    b = [i % 4 == 0, i % 5 == 0, i % 6 == 0]
    if b.count(True) == 1:
        k += 1
print(k)