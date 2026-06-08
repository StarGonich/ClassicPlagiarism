import math

def main():
    n = int(input())
    points = []
    
    for _ in range(n):
        x, y, c = map(int, input().split())
        points.append((x, y, c))
    
    distances = []
    for i in range(n):
        dists = []
        for j in range(n):
            if i != j:
                dx = points[i][0] - points[j][0]
                dy = points[i][1] - points[j][1]
                dist = math.sqrt(dx*dx + dy*dy)
                dists.append((dist, points[j][2]))  
        dists.sort(key=lambda x: x[0])
        distances.append(dists)
    
    results = []
    
    for k in range(1, n, 2): 
        correct = 0
        
        for i in range(n):
            neighbors = distances[i][:k]
            
            white_count = sum(1 for _, color in neighbors if color == 0)
            black_count = k - white_count
            
            predicted_color = 0 if white_count > black_count else 1
            
            if predicted_color == points[i][2]:
                correct += 1
        
        results.append(correct)
    
    for res in results:
        print(res)

if __name__ == "__main__":
    main()