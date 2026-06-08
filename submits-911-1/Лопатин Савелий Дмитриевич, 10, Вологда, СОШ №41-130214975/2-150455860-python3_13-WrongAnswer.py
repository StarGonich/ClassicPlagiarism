N = int(input())
q = 0
for x in range (N, 0, -1):
    q += x
print(q)
for x in range (N, 0, -1):
    print(x, end = ' ')