import math

n = int(input())
k = int(input())
    
divisors = set()
i = 1
while i * i <= n:
    if n % i == 0:
        divisors.add(i)
        divisors.add(n // i)
    i += 1
    
c = n + 1
b = n * (n + 1)
    
for d in divisors:
    p = ((n + 1 + d - 1) // d) * d
    if p <= n + k:
        a = (n // d) * p
            
        if a < b or (a == b and p < c):
            b = a
            c = p

print(c)
