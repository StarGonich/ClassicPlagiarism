n = int(input())
a = []
for i in range(n, 100000):
    for d in range(1, i):
        if i % d == 0:
            a.append(d)
            if len(set(a)) == n and sum(set(a)) == i:
                print(i)
                print(set(a))
                break

