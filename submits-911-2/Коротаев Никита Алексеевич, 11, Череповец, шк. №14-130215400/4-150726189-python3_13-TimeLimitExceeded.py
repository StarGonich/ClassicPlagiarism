from collections import Counter

def distance(p1, p2):
    return ((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)**0.5

def classify_point(distances, points, idx, k):
    distances_to_others = distances[idx][:idx] + distances[idx][idx+1:]
    colors = [point[2] for point in points[:idx] + points[idx+1:]]
    neighbors = sorted(zip(distances_to_others, colors))[:k]
    counts = Counter(color for dist, color in neighbors)
    predicted_color = counts.most_common(1)[0][0]
    true_color = points[idx][2]
    return predicted_color == true_color

n = int(input())
points = []
distances = [[None]*n for _ in range(n)]

for i in range(n):
    xi, yi, ci = map(int, input().split())
    points.append((xi, yi, ci))
    for j in range(i):
        d = distance(points[i][:2], points[j][:2])
        distances[i][j] = d
        distances[j][i] = d

results = []
for k in range(1, n, 2):
    correct_count = sum(classify_point(distances, points, i, k) for i in range(n))
    print(correct_count)