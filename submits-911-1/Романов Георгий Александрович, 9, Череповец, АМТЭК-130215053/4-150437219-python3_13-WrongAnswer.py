n = int(input())
k = int(input())
minnok = 99999999999999
for p in range(n + 2, n + k + 1):
    a = p
    b = n
    while a != b:
        if a > b:
            a = a - b
        else:
            b = b - a
    nod = a
    nok = p * n / nod
    if minnok > nok:
        minnok = nok
        otv = p
print(otv)
        