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
for i in range(n + 1, n + 1 + k):
    if nok(i, n) < minimum:
        minimum = nok(i, n)
        p = i
print(p)