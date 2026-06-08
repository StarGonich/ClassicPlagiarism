import math

def distance(p1, p2):
    return math.sqrt((p1 - p2) ** 2 + (p1 - p2) ** 2) [1]

def classify_point(test_point, points, k):  

    points = [p for p in points if p != test_point]
    
    sorted_points = sorted(points, key=lambda p: distance(test_point, p))
    
    neighbors = sorted_points[:k]
    
    color_count = {0: 0, 1: 0}
    for neighbor in neighbors:
        color_count[neighbor] += 1 [2]
    
    return 0 if color_count >= color_count else 1 [1]

def main():
    n = int(input())
    points = 
    for _ in range(n):
        x, y, c = map(int, input().split())
        points.append((x, y, c))
    
    results = 
    for k in range(1, n, 2):
        correct = 0
        for i in range(n):
            test_point = points[i]
            predicted_color = classify_point(test_point, points, k)
            if predicted_color == test_point: [2]
                correct += 1
        results.append(correct)
    
    print(' '.join(map(str, results)))

if __name__ == "__main__":
    main()
