d = []
n = int(input())
for i in range(1,n):
    if n % i == 0:
        d.append(i)
print(n)
print(*d)