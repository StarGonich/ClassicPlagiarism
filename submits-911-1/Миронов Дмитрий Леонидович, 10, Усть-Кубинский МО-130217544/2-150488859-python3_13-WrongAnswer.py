n = int(input())
if n == 2:
    print(-1)
    exit()
chose = list(range(1, n))
s = sum(chose)
k = s+1
m = s + k
chose.append(k)
print(m)
print(*chose)