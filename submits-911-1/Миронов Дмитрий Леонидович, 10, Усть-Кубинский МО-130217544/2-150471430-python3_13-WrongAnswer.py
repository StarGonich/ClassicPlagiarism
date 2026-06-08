n = int(input())
c = []
for i in range (1, 31):
    if n%i == 0:
        c.append(i)
print(sum(c))
print(*c)