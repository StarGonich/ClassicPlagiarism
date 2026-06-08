n = int(input())
T = int(input())

reklama = []
for _ in range(n):
    t1, t2 = map(int, input().split())
    reklama.append((t1, t2))

start = 0
current_sum = 0

for end in range(n):
    current_sum += reklama[end][1] - reklama[end][0]

    while reklama[end][1] - reklama[start][0] > 3600:
        over = max(0, reklama[start][1] - (reklama[end][1] - 3600))
        current_sum -= over
        start += 1

    if current_sum > T:
        print(max(0, reklama[end][1] - 3600))
        break
else:
    print(-1)