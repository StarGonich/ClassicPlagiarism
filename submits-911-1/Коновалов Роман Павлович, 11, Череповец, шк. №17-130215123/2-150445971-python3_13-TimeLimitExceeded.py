import itertools

n = int(input())
def Del(n):
    d = []
    for i in range(1, n):
        if n % i == 0:
            d.append(i)
    return d
def Prov(h, s):
    for i in itertools.product(s, repeat=n):
        if sum(i) == h and len(i) == len(set(i)):
            return (True, i)
    return (False, [])
a = 0
b = []
for i in range(1, 100):
    s = Del(i)
    if Prov(i, s)[0]:
        a = i
        b = Prov(i, s)[1]
        break
if a:
    print(a)
    print(*b)
else:
    print(-1)