def ch(n): #старое pешение divisiors py
    m = n * (n + 1) // 2
    if (m > 10**9):
        return -1
    divisors = list(range(1, n + 1))
    return m, divisors

n = int(input())
result = ch(n)
if (result == -1):
    print(-1)
else:
    m, divisors = result
    print(m)
    print(' '.join(map(str, divisors)))# выводим как раньше