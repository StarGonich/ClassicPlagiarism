import sys
import math
from collections import Counter

def main():
    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])
    
    points = []
    for i in range(1, n + 1):
        x, y, c = map(int, data[i].split())
        points.append((x, y, c))
    
    def distance(point1, point2):
        return math.sqrt((point1[0] - point2[0]) ** 2 + (point1[1] - point2[1]) ** 2)
    
    results = []
    max_k = n - 1 if (n - 1) % 2 == 1 else n - 2
    
    for k in range(1, max_k + 1, 2): 
        correct_count = 0
        
        for i in range(n):
            current_point = points[i]
            distances = []
            
           
            for j in range(n):
                if j != i:
                    dist = distance(current_point, points[j])
                    distances.append((dist, points[j][2])) 
            
          
            distances.sort(key=lambda x: x[0])
            
          
            nearest_colors = [distances[j][1] for j in range(k)]
            
          
            color_count = Counter(nearest_colors).most_common()
            majority_color = color_count[0][0] 
            
           
            if majority_color == current_point[2]:
                correct_count += 1
        
        results.append(correct_count)
    
   
    print(' '.join(map(str, results)))

if __name__ == "__main__":
    main()
