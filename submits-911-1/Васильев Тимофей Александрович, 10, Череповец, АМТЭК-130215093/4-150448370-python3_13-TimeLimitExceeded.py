n = int(input())
k = int(input())
p = 0
nok = 99999999999
z = max(n, k)
for i in range(min(n, k)):
       if i + z >= n + 1 and i + z <= n + k:
              p1 = i + z
              nok1 = max(p1, n)
              while nok1 % p1 != 0 or nok1 % n != 0:
                     nok1 += 1
              if nok1 < nok:
                     nok = nok1
                     p = p1
print(p)