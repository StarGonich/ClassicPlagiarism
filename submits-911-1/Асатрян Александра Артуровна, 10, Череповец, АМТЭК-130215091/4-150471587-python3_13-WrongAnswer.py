def nok(a, b):
    c = a
    d = b
    while c != d:
        if c > d:
            c -= d
        else:
            d -= c
    return (a * b) // c
n = int(input())
k = int(input())
minimum = n * n + n * k + n
p = 0
if k > n * 3 // 2 or (k > 100 or n>100):
    if n * 3 % 2 == 0:
        print(n * 3 // 2)
    elif n * 4 % 3 == 0:
        print(n * 4 // 3)
    else:
        print(n * 5 // 4)
else:
    
    for i in range(n + 1, n + 1 + k):
        if nok(i, n) < minimum:
            minimum = nok(i, n)
            p = i
    print(p)