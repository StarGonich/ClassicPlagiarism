from math import sqrt


def d(x):
    s = []
    z = 0
    for i in range(1, int(sqrt(x)) + 1):
        if not x % i:
            z += 1
            s.append(i)
    for i in range(z):
        s.append(x // s[z - i - 1])
    return s


n = int(input())
k = int(input())
m = d(n)
for i in range(len(m)):
    z = n * (m[i] + 1) // m[i]
    if z <= n + k:
        print(z)
        break
