def main():
    import sys
    from collections import defaultdict
    
    input = sys.stdin.read
    data = input().splitlines()
    
    N = int(data[0])
    P = list(map(int, data[1].split()))
    K = int(data[2])
    fraud_indices = list(map(int, data[3].split()))
    
   
    fraud_set = set(fraud_indices)

  
    evaluations = [(P[i], i + 1) for i in range(N)]

    evaluations.sort(reverse=True, key=lambda x: x[0])
    
    best_f1 = -1
    best_threshold = -1
    
    TP = 0
    FP = 0
    FN = K 
    prev_threshold = None
    
    for i in range(N):
        current_value, index = evaluations[i]
    
        if index in fraud_set:
            TP += 1
            FN -= 1
        else:
            FP += 1
        
      
        current_threshold = current_value
         
        if current_threshold != prev_threshold:
            prev_threshold = current_threshold
            
     
            precision = TP / (TP + FP) if (TP + FP) > 0 else 0
            recall = TP / (TP + FN) if (TP + FN) > 0 else 0
            
            
            if precision + recall > 0:
                F1 = 2 * precision * recall / (precision + recall)
            else:
                F1 = 0
                
            if F1 > best_f1:
                best_f1 = F1
                best_threshold = current_threshold
            elif F1 == best_f1 and current_threshold < best_threshold:
                best_threshold = current_threshold

    print(best_threshold)

if __name__ == "__main__":
    main()
