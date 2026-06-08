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
print(3*n//2)