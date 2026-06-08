import sys
import math
from collections import defaultdict

def euclidean_distance(p1, p2):
    return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)

def LOO_cross_validation(n, points):
    results = []
    
 
    distances = []
    for i in range(n):
        distances.append([])
        for j in range(n):
            if i != j:
                dist = euclidean_distance(points[i][:2], points[j][:2])
                distances[i].append((dist, points[j][2])) 

  
    for i in range(n):
        distances[i].sort()  

   
    for k in range(1, n, 2):
        correct_count = 0
        for i in range(n):
          
            neighbors_colors = [distances[i][j][1] for j in range(k)]
            predicted_color = max(set(neighbors_colors), key=neighbors_colors.count)
            actual_color = points[i][2]
            if predicted_color == actual_color:
                correct_count += 1
        results.append(correct_count)

    return results


input = sys.stdin.read
data = input().splitlines()
n = int(data[0])
points = [tuple(map(int, line.split())) for line in data[1:n+1]]


results = LOO_cross_validation(n, points)


for result in results:
    print(result)

