import math

# Считываем количество точек
n = int(input())

# Считываем координаты и цвета точек
points = []
for _ in range(n):
    x, y, c = [int(x) for x in input().split()]
    points.append((x, y, c))

# Функция для вычисления евклидова расстояния между двумя точками
def euclidean_distance(p1, p2):
    return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)

# Функция для определения наиболее частого цвета среди k ближайших соседей
def most_frequent_color(neighbors):
    colors = [point[2] for point in neighbors]
    return max(set(colors), key=colors.count)

# Перебираем все нечётные k от n-1 до 1
k_values = list(range(n - 1 if (n - 1) % 2 == 1 else n - 2, 0, -2))
results = []

for k in k_values:
    correct_predictions = 0  # Количество верно классифицированных точек

    for i in range(n):
        # Исключаем саму точку из рассмотрения
        other_points = [points[j] for j in range(n) if j != i]

        # Сортируем точки по расстоянию до текущей точки
        sorted_points = sorted(other_points, key=lambda p: euclidean_distance(points[i], p))

        # Берём k ближайших соседей
        k_nearest = sorted_points[:k]

        # Определяем предсказанный цвет
        predicted_color = most_frequent_color(k_nearest)

        # Сравниваем с реальным цветом
        if predicted_color == points[i][2]:
            correct_predictions += 1

    results.append(correct_predictions)

# Выводим результаты для каждого k
print(' '.join(map(str, results)))
