import math

n = int(input())
points = []
for _ in range(n):
    x, y, c = map(int, input().split())
    points.append((x, y, c))

# Предвычисление расстояний и сортировка ближайших для каждой точки
nearest_sorted = []  # для каждой точки — список индексов ближайших (отсортирован по расстоянию)

for i in range(n):
    distances = []
    for j in range(n):
        if i == j:
            continue
        dx = points[i][0] - points[j][0]
        dy = points[i][1] - points[j][1]
        d = math.sqrt(dx*dx + dy*dy)
        distances.append((d, j))
    # Сортируем по расстоянию, берём индексы
    distances.sort()
    nearest_sorted.append([j for d, j in distances])

# Определяем максимальный k (нечётный)
max_k = n - 1 if (n - 1) % 2 == 1 else n - 2

results = []

# Перебираем все нечётные k от 1 до max_k
for k in range(1, max_k + 1, 2):
    correct = 0
    for i in range(n):
        # Берём k ближайших к точке i (исключая саму i)
        nearest_k = nearest_sorted[i][:k]
        # Считаем цвета
        count0 = 0
        count1 = 0
        for j in nearest_k:
            if points[j][2] == 0:
                count0 += 1
            else:
                count1 += 1
        # Предсказываем цвет
        predicted = 0 if count0 > count1 else 1
        # Проверяем, верно ли предсказание
        if predicted == points[i][2]:
            correct += 1
    results.append(correct)

# Выводим результаты
for res in results:
    print(res)