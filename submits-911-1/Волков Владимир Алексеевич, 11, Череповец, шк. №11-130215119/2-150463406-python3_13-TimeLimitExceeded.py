n = int(input())
m = 1
count = 0
d = []
for i in range(1, 10**9):
    if m % i == 0:
        count += 1
        d.append(i)
    if count == n:
        print(m)
        print(*d)
        break
    else:
        m += 1
        count = 0