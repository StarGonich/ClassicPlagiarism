n = int(input())
k = int(input())

luch_p = n + 1

i = 1
divs = []
while i * i <= n:
    if n % i == 0:
        divs.append(i)
        if i != n // i:
            divs.append(n // i)
    i += 1

for d in divs:
    p = (n // d + 1) * d
    if p <= n + k:
        a, b = n, p
        while b:
            a, b = b, a % b
        g = a
        current_lcm = n * p // g
        
        a, b = n, luch_p
        while b:
            a, b = b, a % b
        g_luch = a
        luch_lcm = n * luch_p // g_luch
        
        if current_lcm < luch_lcm or (current_lcm == luch_lcm and p < luch_p):
            luch_p = p

print(luch_p)