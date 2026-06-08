n = int(input())
k = int(input())
    
a = []

for i in range(100000):
    if n+1 <= i <= n+k:
        a.append(i)
for i in a:
    for j in range(3, i):
        if n % j == 0 and i % j == 0:
            print(i)
            break