n = int(input())
def Del(n):
    count = 0
    d = []
    for i in range(1, n):
        if n % i == 0:
            count += 1
            d.append(i)
    return (count, d)
a = 0
b = []
for i in range(1, 1000):
    m, s = Del(i)
    if m == n and sum(s) == i:
        a = i
        b = s
        break
if a and b:
    print(a)
    print(*b)
else:
    print(-1)