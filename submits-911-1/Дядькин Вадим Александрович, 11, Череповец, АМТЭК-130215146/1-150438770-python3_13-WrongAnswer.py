a = int(input())
b = int(input())
c = int(input())
d = int(input())
k = 0
for i in range(a * 60 + b, c * 60 + d + 1):
    x1 = i // 600
    x2 = (i // 60) % 10
    y1 = (i % 60) // 10
    y2 = (i % 60) % 10
    if i // 60 == i % 60 or (x1 == y2 and x2 == y1) or (x1 + 1 == x2 and x2 + 1 == y1 and y1 + 1 == y2):
        k += 1
print(k)
            

