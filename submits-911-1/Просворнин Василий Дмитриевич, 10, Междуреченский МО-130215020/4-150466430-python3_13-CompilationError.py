import math 

def gcd(a, b) :

   while b: 
        a, b = b, a % b 
   return a 

def lcm(a, b) :


    return a * b // gcd(a, b)

def find_optomal_power(n, k) :
  
    main_lcm = float('inf')
    optimal_p = n + 1

   for p in range(n + 1, n + k + 1) :
       current_lcm = lcm(n , p))
       if current_lcm < min_lcm
       min_lcm = current_lcm
       optimal_p = p

return optimal_p

n = int (input(n))
k = int (input(k))

if not(1 <= n <= 10**12 and 1 <= k 10**12) :
     print 
else:  
     result = find_optimal_power(n, k)
print 