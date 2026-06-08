def p(x):
    i = 2
    while x > 1:
        if x % i == 0:
            x //= i
        else:
            i += 1
    return i
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
for i in range(n + p(n), n + k + 1, p(n)):
    if nok(n, i) < m:
        m = nok(n, i)
        q = i
print(q)