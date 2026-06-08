n = int(input())
if n == 2:
    print(-1)
    exit()
c = list(range(1, n))
s = sum(c)
m = s + n
c.append(n)
print(m)
print(*c)