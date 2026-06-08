n = int(input())
k = int(input())
minn = 10**9
p = int()
for i in range(n + 1, n + k + 1):  # p
    for x in range(max(n, i), n * i):  # NOK
        if x % n == 0 and x % i == 0:
            if minn > x:
                minn = x
                p = i
print(p)