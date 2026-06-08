n = int(input())
points = []
for _ in range(n):
    x, y, c = map(int, input().split())
    points.append((x, y, c))

neighbors = []
for i in range(n):
    dists = []
    xi, yi, ci = points[i]
    for j in range(n):
        if i == j:
            continue
        xj, yj, cj = points[j]
        dist = (xi - xj)**2 + (yi - yj)**2 
        dists.append((dist, cj))
    dists.sort(key=lambda x: x[0]) 
    neighbors.append(dists)


results = []
for k in range(1, n, 2):
    correct = 0
    for i in range(n):
        
        nearest = neighbors[i][:k]
        count0 = sum(1 for _, color in nearest if color == 0)
        count1 = k - count0
        
        predicted = 0 if count0 > count1 else 1
        if predicted == points[i][2]:
            correct += 1
    results.append(correct)


for res in results:
    print(res)