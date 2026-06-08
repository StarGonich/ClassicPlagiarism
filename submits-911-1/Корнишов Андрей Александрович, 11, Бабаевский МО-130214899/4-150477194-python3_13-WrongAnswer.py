n = int(input())
k = int(input())
a = 0
p = n
NOK1 = 10**10
while a != 10:
    if n%2 == 0 and n%3 != 0:
        p+=2
    else:
        p += 1
    if p <= n + k:
        if p*n < NOK1:
            NOK = p*n
        else:
            NOK = NOK1
        for i in range(p,NOK+1):
            i += 1
            if i % n == 0 and i % p == 0 and i <= NOK:
                NOK1 = i
                p1 = p
    a += 1
print(p1)