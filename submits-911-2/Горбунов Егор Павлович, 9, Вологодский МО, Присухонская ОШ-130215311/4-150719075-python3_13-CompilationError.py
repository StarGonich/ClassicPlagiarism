import math
from collections import Counter

def distance(p1, p2):
    return math.sqrt((p1 - p2) ** 2 + (p1 - p2) ** 2) [1]

def k_nearest_neighbors(points, k, test_point):
    sorted_points = sorted(points, key=lambda p: distance(p, test_point))
    neighbors = sorted_points[1:k+1]
    return neighbors

def classify_point(points, k):
    correct = 0
    for i in range(len(points)):
        test_point = points[i]
        neighbors = k_nearest_neighbors(points, k, test_point)
        colors = Counter(p for p in neighbors) [2]
        predicted_color = colors.most_common(1)
        if predicted_color == test_point: [2]
            correct += 1
    return correct

def main():
    n = int(input())
    points = 
    for _ in range(n):
        x, y, c = map(int, input().split())
        points.append((x, y, c))
    
    results = 
    for k in range(1, n, 2):
        correct = classify_point(points, k)
        results.append(correct)
    
    print(.join(map(str, results)))

