n = int(input())
cnt = 0
for i in range(4, n+1):
    if sum([i % 4 == 0, i % 5 == 0, i % 6 == 0]) == 1:
        cnt += 1
print(cnt)
