n = int(input())
c = []
f = False
for i in range(10**9):
    i += 1
    c = []
    for j in range(1, i + 1):
        if i % j == 0:
            c.append(j)
    for j in range(len(c)):
        if n + j == len(c):
            break
        if sum(c[j:n + j]) == i and len(c[j:n + j]) == n:
            print(i)
            print(" ".join(str(c[i]) for i in range(len(c[j:n + j]))))
            f = True
            break
    if f:
        break