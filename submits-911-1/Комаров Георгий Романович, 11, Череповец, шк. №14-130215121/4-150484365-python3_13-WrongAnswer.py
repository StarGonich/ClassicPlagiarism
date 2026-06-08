n = int(input())
k = int(input())
nok = n + 1
for p in range((n + 1), (n + k)):
    if (nok % n != 0) and (nok % p != 0):
        nok += 1
print(nok)

        
    