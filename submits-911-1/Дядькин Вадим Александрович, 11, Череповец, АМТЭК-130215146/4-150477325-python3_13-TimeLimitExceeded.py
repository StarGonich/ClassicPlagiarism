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
elif k > n / 6 and n % 6 == 0:
    print(n * 7 // 6)
elif k > n / 7 and n % 7 == 0:
    print(n * 8 // 7)
elif k > n / 8 and n % 8 == 0:
    print(n * 9 // 8)
elif k > n / 9 and n % 9 == 0:
    print(n * 10 // 9)
elif k > n / 10 and n % 10 == 0:
    print(n * 11 // 10)
elif k > n / 11 and n % 11 == 0:
    print(n * 12 // 11)
elif k > n / 12 and n % 12 == 0:
    print(n * 13 // 12)
elif k > n / 13 and n % 13 == 0:
    print(n * 14 // 13)
elif k > n / 14 and n % 14 == 0:
    print(n * 15 // 14)
elif k > n / 15 and n % 15 == 0:
    print(n * 16 // 15)
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