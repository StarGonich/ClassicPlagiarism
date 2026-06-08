f = 10**10
n = int(input())
k = int(input())
p = n + 1
a = 0

for i in range(abs(n + k)):
    b = p
    for h in range(n * k):
        if b % p == 0 and b % n == 0 and b < f:
            a = p
            f = b
        b += 1
    p += 2
print(a)