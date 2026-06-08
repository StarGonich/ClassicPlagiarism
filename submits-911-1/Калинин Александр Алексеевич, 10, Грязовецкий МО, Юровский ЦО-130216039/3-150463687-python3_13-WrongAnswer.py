N = int(input())
T = int(input())

ads = []
for _ in range(N):
    t1, t2 = map(int, input().split())
    ads.append((t1, t2))

left = 0
current_sum = 0
result = -1

for right in range(N):
    current_sum += ads[right][1] - ads[right][0]
    # Убираем из окна вставки, которые вышли за границы 3600 секунд
    while ads[right][0] - ads[left][0] >= 3600:
        current_sum -= ads[left][1] - ads[left][0]
        left += 1
    # Проверяем, если окно длиной 3600 секунд
    if ads[right][0] - ads[left][0] < 3600:
        if current_sum > T:
            result = ads[left][0]
            break

print(result)