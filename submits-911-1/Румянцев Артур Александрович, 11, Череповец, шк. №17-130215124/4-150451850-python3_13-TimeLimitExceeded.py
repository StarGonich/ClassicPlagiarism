n = int(input())
k = int(input())

noks = []

for p in range(n+1, n+k+1):
    for num in range(1, 10**18):
        if num % n == 0 and num % p == 0:
            noks.append([num, p])
            break
        
print((min(noks))[1])      