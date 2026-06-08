def distance(p1, p2):
    return ((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)**0.5

def classify_point(points, idx, k):
    point = points[idx]
    others = [(distance(point[:2], other[:2]), other[2]) for i, other in enumerate(points) if i != idx]
    neighbors = sorted(others, key=lambda x: x[0])
    top_k_neighbors = neighbors[:k]
    colors = [color for _, color in top_k_neighbors]
    predicted_color = max(set(colors), key=colors.count)
    true_color = point[2]
    return predicted_color == true_color

n = int(input())
points = []
for line in range(n):
    xi, yi, ci = [int(x) for x in input().split()]
    points.append((xi, yi, ci))
    
results = []
for k in range(1, n, 2):
    correct_count = sum(classify_point(points, i, k) for i in range(n))
    results.append(correct_count)
for i in results:
    print(i)