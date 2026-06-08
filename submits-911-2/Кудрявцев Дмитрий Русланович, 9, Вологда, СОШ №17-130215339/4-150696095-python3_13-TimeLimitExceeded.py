import math

# Считываем количество точек
n = int(input())

# Сохраняем точки в виде списка кортежей (x, y, color)
points = []
for _ in range(n):
    x, y, c = [int(x) for x in input().split()]
    points.append((x, y, c))

# Функция для вычисления расстояния между двумя точками
def distance(p1, p2):
    return math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

# Перебираем все нечётные k от 1 до n-1 (или n-2, если n-1 чётное)
k_values = range(1, n, 2)  # генерируем нечётные числа от 1 до n-1

# Для каждого k считаем количество верно классифицированных точек
for k in k_values:
    correct_count = 0  # счётчик верно классифицированных точек

    # Перебираем каждую точку как «тестируемую»
    for i in range(n):
        test_point = points[i]  # текущая тестируемая точка
        other_points = points[:i] + points[i+1:]  # все остальные точки

        # Сортируем остальные точки по расстоянию до тестируемой
        sorted_points = sorted(other_points, key=lambda p: distance(test_point, p))

        # Берём k ближайших точек
        k_nearest = sorted_points[:k]

        # Считаем, какой цвет встречается чаще среди k ближайших точек
        color_count = [0, 0]  # [количество белых (0), количество чёрных (1)]
        for point in k_nearest:
            color_count[point[2]] += 1

        # Определяем предсказанный цвет (тот, который встречается чаще)
        predicted_color = 0 if color_count[0] >= color_count[1] else 1

        # Если предсказанный цвет совпадает с реальным — увеличиваем счётчик
        if predicted_color == test_point[2]:
            correct_count += 1

    # Выводим количество верно классифицированных точек для текущего k
    print(correct_count)
