import itertools

k = int(input())
found = False

for x in range(1, 1000):
    divisors = [i for i in range(1, x) if x % i == 0]
    
    if len(divisors) >= k:
        for combo in itertools.combinations(divisors, k):
            if sum(combo) == x:
                print(x)
                print(",".join(map(str, combo)))
                found = True
                break
    if found:
        break

if not found:
    print(-1)