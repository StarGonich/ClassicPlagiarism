n = int(input())
a = []
for i in range(1, 10**9):
    for d in range(1, i):
        if i % d == 0:
            a.append(d)
        if len(set(a)) == n and sum(set(a)) == i:
            print(i)
            print(set(a))
            break