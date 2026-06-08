n = int(input())
b = [0]*n
for i in range(0, n+1, 4):
    if i > 0:
        b[i-1] += 1
for i in range(0, n+1, 5):
    if i > 0:
        b[i-1] += 1
for i in range(0, n+1, 6):
    if i > 0:
        b[i-1] += 1
print(len(list(filter(lambda x: x==1, b))))
