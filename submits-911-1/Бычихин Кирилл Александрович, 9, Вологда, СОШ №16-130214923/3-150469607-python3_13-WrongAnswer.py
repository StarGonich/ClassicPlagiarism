n, T = int(input()), int(input())
a = [tuple(map(int, input().split())) for _ in range(n)]
l = 0
sum_x = 0
res = -1
for r in range(n):
    sum_x += a[r][1] - a[r][0]
    while a[l][0] + 3600 <= a[r][0]:
        sum_x -= a[l][1] - a[l][0]
        l += 1
    if sum_x > T:
        if res == -1 or a[l][0] < res:
            res = a[l][0]
print(res)