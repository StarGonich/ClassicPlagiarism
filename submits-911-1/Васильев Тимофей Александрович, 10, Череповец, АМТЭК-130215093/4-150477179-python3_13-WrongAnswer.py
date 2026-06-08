n = int(input())
k = int(input())
p = 0
nok = 999999999999999
z = max(n, k)
v = min(n,k)
for i in range(v // 2):
       p1 = v - i + z
       if p1 >= n + 1 and p1 <= n + k:
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