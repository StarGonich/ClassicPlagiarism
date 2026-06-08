import itertools

n = int(input())

for m in range(1, 109110):
    divs = []
    for i in range(1, int(m**0.5) + 1):
        if m % i == 0:
            divs.append(i)
            if i != m // i:
                divs.append(m // i)
    divs = list(set(divs))
    if len(divs) < n:
        continue

    f = False
    for i in itertools.combinations(divs, n):
        if sum(i) == m:
            print(m)
            print(*i)
            f = True
            break
    if f:
        break

if not f:
    print(-1)