def d(x):
    s = []
    for i in range(1, x):
        if not x % i:
            s.append(i)
    return s


n = int(input())
k = int(input())
m = d(n)
for i in range(len(m)):
    z = n * (m[i] + 1) // m[i]
    if z <= n + k:
        print(z)
        break
