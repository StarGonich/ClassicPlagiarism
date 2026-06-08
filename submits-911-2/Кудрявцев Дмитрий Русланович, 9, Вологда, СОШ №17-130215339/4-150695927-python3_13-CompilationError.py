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
    return math.