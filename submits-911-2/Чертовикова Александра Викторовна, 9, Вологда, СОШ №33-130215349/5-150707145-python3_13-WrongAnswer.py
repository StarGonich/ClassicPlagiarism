def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    N = int(data[0])
    P = list(map(int, data[1].split()))
    K = int(data[2])
    fraudulent_indices = list(map(int, data[3].split()))
    
    fraud_set = set(fraudulent_indices)
    
 
    fraud_scores = [P[i - 1] for i in fraud_set]

    unique_scores = sorted(set(P))
    
    best_F1 = -1
    best_threshold = -1
    
    for T in unique_scores:
        TP = sum(1 for i in range(N) if P[i] >= T and (i + 1) in fraud_set)
        FP = sum(1 for i in range(N) if P[i] >= T and (i + 1) not in fraud_set)
        FN = sum(1 for i in fraud_set if P[i - 1] < T)
        TN = N - TP - FP - FN
        

        precision = TP / (TP + FP) if (TP + FP) > 0 else 0
        recall = TP / (TP + FN) if (TP + FN) > 0 else 0
        
        if precision + recall > 0:
            F1 = 2 * precision * recall / (precision + recall)
        else:
            F1 = 0
        
 
        if F1 > best_F1 or (F1 == best_F1 and T < best_threshold):
            best_F1 = F1
            best_threshold = T
            
    print(best_threshold)

if __name__ == "__main__":
    main()
