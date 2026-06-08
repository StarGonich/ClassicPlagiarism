n = int(input())
a = []
for i in range(1, 100):
    a = []
    sum = 0
    for j in range(1, i):
        if i % j == 0:
            a.append(j)
            sum += j
    if i == sum and len(a) == n:
        print(i)
        for i in a:
            print(i, end=' ')
        