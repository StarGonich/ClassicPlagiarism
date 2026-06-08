n = int(input())
k = int(input())
x=0
for p in range(n + 1, n + k + 1):
    if x % p == 0 and x % n == 0 or n % n == 0 and n % p == 0:
        a = max(p, n)
    else:
        p += 1
print(a)
