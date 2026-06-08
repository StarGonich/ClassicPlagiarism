n = int(input())
k = int(input())
pmn = n + 1
pmx = n + k
nok = pmx * k
gh = nok
for i in range(k):
    p1 = pmn + i
    for j in range(nok - p1):
        p2 = p1 + j
        if (p2 % k) == 0 and (p2 % p1) == 0 and gh > p2:
            gh = p2
print(gh)