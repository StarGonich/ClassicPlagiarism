n, k, p, z, a, q = int(input()), int(input()), 0, [], [], 0
if n < k:
    p = k + 1
else:
    p = n + 1
while True:
    if p >= n + 1 and p <= n + k:
        z.append(p)
    else:
      break
    p += 1
for i in z:
  q = i
  while True:
      if q % i == 0 and q % n == 0:
          break
      q += 1
  a.append(q)  
f = min(a)
print(z[a.index(f)])