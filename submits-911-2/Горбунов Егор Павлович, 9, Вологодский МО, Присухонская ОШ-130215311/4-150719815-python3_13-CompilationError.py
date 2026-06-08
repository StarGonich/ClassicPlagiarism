import math
from collections import Counter

def distance(p1, p2):
    return math.sqrt((p1 - p2) ** 2 + (p1 - p2) ** 2) [1]

def k_nearest_neighbors(points, k, test_point):
    # Сортируем точки по расстоянию до тестовой точки
    sorted_points = sorted(points, key=lambda p: distance(p, test_point))
    # Берем первые k точек, исключая саму тестовую точку
    neighbors = sorted_points[1:k+1]
    return neighbors

def classify_point(points, k):
    correct = 0
    for i in range(len(points)):
        test_point = points[i]
        neighbors = k_nearest_neighbors(points, k, test_point)
        # Считаем количество соседей каждого цвета
        colors = Counter(p for p in neighbors) [2]
        # Определяем преобладающий цвет
        predicted_color = colors.most_common(1)
        # Если предсказанный цвет совпадает с реальным, увеличиваем счетчик
        if predicted_color == test_point: [2]
            correct += 1
    return correct

def main():
    # Считываем входные данные
    n = int(input())
    points = 
    for _ in range(n):
        x, y, c = map(int, input().split())
        points.append((x, y, c))
    
    # Перебираем все нечетные k
    results = 
    for k in range(1, n, 2):
        correct = classify_point(points, k)
        results.append(correct)
    
    # Выводим результаты
    print(' '.join(map(str, results)))

if __name__ == :
    main()
