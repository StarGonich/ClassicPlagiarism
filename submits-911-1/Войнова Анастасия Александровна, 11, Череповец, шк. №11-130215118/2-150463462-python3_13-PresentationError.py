from itertools import *
def d(num):
    res = []
    for i in range(1, num // 2 + 1):
        if num % i == 0:
            res.append(i)
    return res
n = int(input())
f = False
for x in range(1, 10**9):
    l = d(x)
    for y in combinations(l, 3):
        if x == sum(y):
            print(x)
            print(*y)
            f = True
            break
    if f:
        break
if not f:
    print(-1)