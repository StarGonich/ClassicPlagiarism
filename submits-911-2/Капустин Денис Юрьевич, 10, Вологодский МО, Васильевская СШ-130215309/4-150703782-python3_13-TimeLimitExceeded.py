import math
def euclidean_distance_sq(p1, p2):
    return (p1['x'] - p2['x'])**2 + (p1['y'] - p2['y'])**2
def predict_color(target_point, neighbors, k):
    color_counts = {0: 0, 1: 0}
    neighbors.sort(key=lambda neighbor: neighbor['distance_sq'])
    k_nearest = neighbors[:k]
    for neighbor in k_nearest:
        color_counts[neighbor['c']] += 1
    if color_counts[0] > color_counts[1]:
        return 0
    elif color_counts[1] > color_counts[0]:
        return 1
    else:
        return 0
def solve():
    n = int(input())
    points = []
    for _ in range(n):
        x, y, c = map(int, input().split())
        points.append({'x': x, 'y': y, 'c': c})
    results = {}
    for k in range(1, n, 2):
        correctly_classified_count = 0
        for i in range(n):
            target_point = points[i]
            neighbors_for_target = []
            for j in range(n):
                if i != j:
                    dist_sq = euclidean_distance_sq(target_point, points[j])
                    neighbors_for_target.append({
                        'x': points[j]['x'],
                        'y': points[j]['y'],
                        'c': points[j]['c'],
                        'distance_sq': dist_sq
                    })
            predicted_c = predict_color(target_point, neighbors_for_target, k)
            if predicted_c == target_point['c']:
                correctly_classified_count += 1
        results[k] = correctly_classified_count
    for k in sorted(results.keys()):
        print(results[k])
solve()