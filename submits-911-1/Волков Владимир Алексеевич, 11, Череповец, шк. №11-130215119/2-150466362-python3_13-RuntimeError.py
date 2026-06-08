n = int(input())
m = 1
count = 0
d = []
while count != n:
    if m % i == 0:
        count += 1
        d.append(i)
    if count == n:
        print(m)
        print(*d)
    else:
        m += 1
        count = 0