n = int(input())
k = int(input())
total = 0
for i in range (n+1,n+k):
    for j in range (2,n+1):
        if i % j == 0 and n % j == 0:
            total = i
            print(total)
            break
            
        if total > 0:
            break
print(total)

