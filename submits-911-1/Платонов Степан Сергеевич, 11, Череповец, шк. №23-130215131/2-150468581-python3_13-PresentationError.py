def find_num(k):
    # Простой перебор
    for x in range(1, 1000):
        factors = []
        
        # Ищем все делители (кроме самого числа)
        for i in range(1, x):
            if x % i == 0:
                factors.append(i)
        
        # Проверяем комбинации из k делителей
        from itertools import combinations
        for combo in combinations(factors, k):
            if sum(combo) == x:
                return x, combo
    
    return None

t= int(input())
print()
answer = find_num(t)

if answer:
    number, parts = answer
    print(f" {number}")
    print(f"{parts}")
   
else:
    print(-1)