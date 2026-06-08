a = int(input())
x = int(input())
y = int(input())
s = []
b = []
for i in range(a):
    b.append(i + 1)

    for j in range(x):
        q = list(map(int, input().split()))
for i in range(a):
    if i % 2 == 0:
        s.append(b[-i])
    else:
        s.append(b[i + 1])
print(*s)