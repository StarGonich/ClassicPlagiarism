n = int(input())
T = int(input())

l = 0
curr_sum = 0
res = -1

ads = []
for _ in range(n):
    t1, t2 = map(int, input().split())
    ads.append((t1, t2))

for r in range(n):
    curr_sum += ads[r][1] - ads[r][0]
    while ads[l][0] + 3600 <= ads[r][0]:
        curr_sum -= ads[l][1] - ads[l][0]
        l += 1
    if curr_sum > T:
        start = ads[l][0]
        if res == -1 or start < res:
            res = start

print(res)