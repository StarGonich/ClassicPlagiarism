import math

n = int(input())

r = 0
sqrt_n = int(math.isqrt(n))  


for i in range(1, sqrt_n + 1):
    if n % i == 0:
        r += i 
        if i != n // i and n // i != n:
            r += n // i 

print(r)