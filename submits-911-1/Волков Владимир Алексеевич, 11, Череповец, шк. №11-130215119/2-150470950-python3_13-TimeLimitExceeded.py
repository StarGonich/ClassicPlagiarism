n = int(input())
m = 0
count = 0
d = '123'
i = 1
while count != n:
    m += 1
    count = 0
    if m % i == 0:
        count += 1
        d += str(i)
print(m)
for x in range(len(d)):
    print(d[x], end=' ')
 