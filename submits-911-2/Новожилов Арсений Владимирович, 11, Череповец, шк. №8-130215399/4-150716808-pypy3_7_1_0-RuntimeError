line1 = input().strip()
points = []
for _ in range(n):
    line = input().strip().split()
    x, y, c = int(line[0]), int(line[1]), int(line[2])
    points.append((x, y, c))

correct_counts = [0] * (n + 1)
        
for i in range(n):
    neighbors_with_dist = []
    for j in range(n):
        if i == j:
            continue
        dist_sq = (points[i][0] - points[j][0])**2 + (points[i][1] - points[j][1])**2
        neighbors_with_dist.append((dist_sq, points[j][2]))
            
    neighbors_with_dist.sort()
            
    white_count = 0
    black_count = 0
    actual_color = points[i][2]

    for j in range(n - 1):
        color = neighbors_with_dist[j][1]
        if color == 0:
            white_count += 1
        else:
            black_count += 1
        k = j + 1
        if k % 2 == 1:
            predicted_color = 0 if white_count > black_count else 1
            if predicted_color == actual_color:
                correct_counts[k] += 1
        
output_list = []
for k in range(1, n, 2):
    output_list.append(str(correct_counts[k]))        
print("\n".join(output_list))
