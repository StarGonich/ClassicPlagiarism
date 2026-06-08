n = int(input())
for i in range(10,10000):
    d = []
    for j in range(1,n+1):
        if i % j == 0:
            d.append(j)
    if sum(d) == i:
        print(i)
        print(*d)
        break
print(-1)