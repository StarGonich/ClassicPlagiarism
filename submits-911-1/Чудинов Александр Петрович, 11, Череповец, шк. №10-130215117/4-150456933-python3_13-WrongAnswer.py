n = int(input())
k = int(input())
total = 0
ep = 0
for i in range (n+1,n+k):
    for j in range (2,n+1):
        if i % j == 0 and n % j == 0:
            if total == 0:
                ep = i   
            total = i
            
            break
print(ep)


