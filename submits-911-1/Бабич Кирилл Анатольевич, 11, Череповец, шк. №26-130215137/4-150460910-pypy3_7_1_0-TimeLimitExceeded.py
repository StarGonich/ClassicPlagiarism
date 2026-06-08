import math 
n = int(input())
k = int(input())
best_p = None
best_lcm = None
for p in range(n+1, n+k+1):
    lcm = n*p // math.gcd(n,p)
    if best_p == None or lcm < best_lcm:
        best_p = p
        best_lcm = lcm
print(best_p)