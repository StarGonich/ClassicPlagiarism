import math

def solve():
    n = int(input())
    k = int(input())
    
   
    low = n + 1
    high = n + k
    
    best_p = high 
    best_lcm = n * high  
    
 
    divisors = set()
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            divisors.add(i)
            divisors.add(n // i)
    
  
    divisors.add(1)
    
   
    for d in divisors:
        
        min_p = ((low + d - 1) // d) * d
        
        if min_p <= high:
            candidate_p = min_p
            candidate_lcm = n * candidate_p // d
            
            if candidate_lcm < best_lcm or (candidate_lcm == best_lcm and candidate_p < best_p):
                best_lcm = candidate_lcm
                best_p = candidate_p
    
    
    

    for p in range(low, min(high, low + 1000) + 1):
        g = math.gcd(n, p)
        current_lcm = n * p // g
        
        if current_lcm < best_lcm or (current_lcm == best_lcm and p < best_p):
            best_lcm = current_lcm
            best_p = p
    
    print(best_p)

if __name__ == "__main__":
    solve()