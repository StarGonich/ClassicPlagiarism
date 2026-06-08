def find_number_with_divisors(n):
    def divisors(num):
        result = []
        for i in range(1, int(num ** 0.5) + 1):
            if num % i == 0:
                result.append(i)
                if i != num // i and i != 1:
                    result.append(num // i)
        return sorted(result)
    
    max_value = 10**9
    for m in range(max_value//2, max_value): 
        divs = divisors(m)
        
        from itertools import combinations
        for comb in combinations(divs, n):
            if sum(comb) == m:
                print(m)
                print(" ".join(map(str, comb)))
                return
                
    print(-1)

n = int(input())
find_number_with_divisors(n)