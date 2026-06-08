import sys
input = sys.stdin.readline

N = int(input())
T = int(input())

ad = [tuple(map(int, input().split())) for _ in range(N)]

# Два указателя
j = 0
cur = 0
best_start = -1

for i in range(N):
    start = ad[i][0]
    end = start + 3600

    # расширяем правую границу, пока интервалы пересекаются с окном
    while j < N and ad[j][0] < end:
        t1, t2 = ad[j]
        # добавляем пересечение
        cur += max(0, min(t2, end) - max(t1, start))
        j += 1

    # проверяем условие
    if cur > T:
        best_start = start
        break

    # теперь передвигаем левый указатель: убираем вклад интервала i
    t1, t2 = ad[i]
    cur -= max(0, min(t2, end) - max(t1, start))

print(best_start)
