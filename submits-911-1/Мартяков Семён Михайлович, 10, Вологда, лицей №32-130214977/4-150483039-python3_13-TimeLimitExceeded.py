n = int(input())
k = int(input())

ans = n+1


def nok(a,b):
    a1=a
    b1=b
    while b != 0:
        a, b = b, a%b
    nok = a1*b1//a
    return nok

nok1 = nok(n, n+1)

for i in range(n+1, n+k+1):
    if nok(i, n) < nok1:
        ans = i
        nok1 = nok(i,n)

print(ans)