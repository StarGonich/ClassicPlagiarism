n = (int(input()))
k = (int(input()))
d = []
i = 1
while i * i <= n:
    if n % i == 0:
        d.append(i)
        if i * i != n:
            d.append(n // i)
    i += 1
d.sort(reverse=True)
for i in d:
    p = ((n + 1 + i - 1) // i) * i
    if p <= n + k:
        print(p)
        break