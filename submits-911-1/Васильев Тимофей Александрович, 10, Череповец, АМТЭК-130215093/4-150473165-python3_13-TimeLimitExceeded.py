n = int(input())
k = int(input())
p = 0
nok = 999999999999999999999999
z = max(n, k)
for i in range(min(n, k)):
       if i + z >= n + 1 and i + z <= n + k:
              p1 = i + z
              a = max(p1, n)
              b = min(p1, n)
              while a - b != 0:
                     if a > b:
                            a = a - b
                     else:
                            b = b - a
              nok1 = p1 * n / a
              if nok1 < nok:
                     nok = nok1
                     p = p1
print(p)