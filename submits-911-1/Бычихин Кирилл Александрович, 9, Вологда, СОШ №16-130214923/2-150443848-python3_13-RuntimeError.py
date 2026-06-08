n = int(input())

m = None

for i in range(n, 31):
    if i == n:
        continue

    if i%n == 0:
        m = i
        break

print(m)

d = []

for i in range(0, m):
    if i == 0:
        continue
    if m%i == 0:
        d.append(i)

if sum(d) != m:
    print(-1)
    exit(0)

for i in d:
    print(i, end=' ')
