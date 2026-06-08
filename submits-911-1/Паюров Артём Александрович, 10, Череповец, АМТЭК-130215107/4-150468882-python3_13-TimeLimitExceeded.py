n = int(input())
k = int(input())
l = n + 1
r = n + k
pmin = 1000000000001
nok = 1000000000001
for i in range(n+1,min(l*n, r)):
    a = i
    b = n
    while a%b != 0:
        a, b = b, a%b
    if n*l/b < nok:
        nok = n*l/b
        pmin = i
print(pmin)