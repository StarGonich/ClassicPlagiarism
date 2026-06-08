import math
def distance(point1, point2):
    return math.sqrt((point1[0] - point2[0])**2 + (point1[1] - point2[1])**2)
def solve():
    n = int(input())
    points = []
    for _ in range(n):
        x, y, c = map(int, input().split())
        points.append((x, y, c))
    for k in range(1, n, 2):
        correct_predictions = 0
        for i in range(n):
            distances = []
            for j in range(n):
                if i != j:
                    dist = distance((points[i][0], points[i][1]), (points[j][0], points[j][1]))
                    distances.append((dist, points[j][2]))
            distances.sort(key=lambda x: x[0])
            neighbors = distances[:k]
            color_counts = {0: 0, 1: 0}
            for _, color in neighbors:
                color_counts[color] += 1
            predicted_color = 0 if color_counts[0] > color_counts[1] else 1
            if predicted_color == points[i][2]:
                correct_predictions += 1
        print(correct_predictions)
solve()