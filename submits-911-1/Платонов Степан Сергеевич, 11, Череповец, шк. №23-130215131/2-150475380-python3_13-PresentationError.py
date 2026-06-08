import itertools

def find_num(k):
    for x in range(1, 1000):
        factors = []
        
        
        for i in range(1, x):
            if x % i == 0:
                factors.append(i)
        
        
        if len(factors) < k:
            continue
            
       
        for combo in itertools.combinations(factors, k):
            if sum(combo) == x:
                return x, combo
    
    return None

try:
    t = int(input())
    
    
    if t <= 0:
        print(-1)
    else:
        answer = find_num(t)

        if answer:
            number, parts = answer
            print(f"{number}")
            print(", ".join(map(str, parts)))
        else:
            print(-1)
except (ValueError, EOFError):
    print(-1)