import math
import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    points = []
    idx = 1
    for _ in range(n):
        x = int(data[idx]); y = int(data[idx+1]); c = int(data[idx+2])
        idx += 3
        points.append((x, y, c))
    
    sorted_neighbors = []
    for i in range(n):
        neighbors = []
        x1, y1, _ = points[i]
        for j in range(n):
            if i != j:
                x2, y2, c2 = points[j]
                dx = x1 - x2
                dy = y1 - y2
                dist_sq = dx * dx + dy * dy 
                neighbors.append((dist_sq, c2))
        neighbors.sort(key=lambda x: x[0])
        sorted_neighbors.append(neighbors)
    max_k = n if n % 2 == 1 else n - 1
    results = [0] * ((max_k + 1) // 2)
    
    for i in range(n):
        white = 0
        black = 0
        true_color = points[i][2]
        
        for k_idx, (_, color) in enumerate(sorted_neighbors[i]):
            if color == 0:
                white += 1
            else:
                black += 1
            
            current_k = k_idx + 1
            if current_k % 2 == 1:
                predicted = 0 if white > black else 1
                if predicted == true_color:
                    results[current_k // 2] += 1
    
    for res in results:
        print(res)

if __name__ == "__main__":
    main()