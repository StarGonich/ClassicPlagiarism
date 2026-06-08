n, k, p, z, a, q = int(input()), int(input()), 0, 999999999, 0, 0
if n < k:
    p = k + 1
else:
    p = n + 1
while True:
    if p >= n + 1 and p <= n + k:
        q = p
        while True:
            if q >= z:
                break
            if q % p == 0 and q % n == 0:
                z, a = q, p
                break
            if p % 2 != 0 or n % 2 != 0:
                q += 1
            else:
                q += 2
    else:
      break
    p += 1
print(a)