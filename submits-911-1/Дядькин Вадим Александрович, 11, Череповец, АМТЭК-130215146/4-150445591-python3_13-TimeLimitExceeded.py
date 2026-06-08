def nok(x, y):
    z = x * y
    while x != y:
        if x > y:
            x -= y
        else:
            y -= x
    return z // x
n = int(input())
k = int(input())
m = 99999999
for i in range(n + 1, n + k + 1):
    if nok(n, i) < m:
        m = nok(n, i)
        q = i
print(q)