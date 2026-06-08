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
q = 0
if k > n:
    print(2 * n)
elif k > n / 2 and n % 2 == 0:
    print(n * 3 // 2)
elif k > n / 3 and n % 3 == 0:
    print(n * 4 // 3)
elif k > n / 4 and n % 4 == 0:
    print(n * 5 // 4)
elif k > n / 5 and n % 5 == 0:
    print(n * 6 // 5)
else:
    if p(n) < k:
        w = p(n)
    else:
        w = 1
        for i in range(n + w, n + k + 1, w):
            if nok(n, i) < m:
                m = nok(n, i)
                q = i
        print(q)