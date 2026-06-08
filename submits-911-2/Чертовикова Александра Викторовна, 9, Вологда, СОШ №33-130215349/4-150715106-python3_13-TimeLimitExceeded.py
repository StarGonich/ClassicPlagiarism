import sys
import math
from collections import Counter

def read_input():
    n = int(sys.stdin.readline().strip())
    points = [tuple(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]
    return n, points

def euclidean_distance(p1, p2):
    return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)

def main():
    n, points = read_input()
    
    results = []
   
    for k in range(1, n, 2):
        correct_predictions = 0
        
     
        for i in range(n):
           
            query_point = points[i]
            distances = []
            
           
            for j in range(n):
                if j != i:
                    distance = euclidean_distance(query_point, points[j])
                    distances.append((distance, points[j]))
         
            distances.sort(key=lambda x: x[0])
            nearest_colors = [distances[j][1][2] for j in range(k)]
            
            color_count = Counter(nearest_colors)
      
            predicted_color = color_count.most_common(1)[0][0]
            
       
            if predicted_color == query_point[2]:
                correct_predictions += 1
                
        results.append(correct_predictions)
    
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
