k = int(input())
for n in range(1,(10**9)+1):
    d = []; m = int(n**0.5) 
    for i in range(1, m + 1): 
        if n % i == 0: d.append(i); d.append(n // i) 
    if m * m == n: d.remove(m) 
    d.sort() 
    if k == sum(d) and i == sum(d):
        print(i)
        print(d)
        break
            