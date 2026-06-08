n = int(input())
n = n * 2
ans = []
k = 0
for i in range(1, (n // 2) + 1):
    if n % i == 0:
        ans.append(i)
        k += i
ans.reverse()
print(k)
print(*ans)