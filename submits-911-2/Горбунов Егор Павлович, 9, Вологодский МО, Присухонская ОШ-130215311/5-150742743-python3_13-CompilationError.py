def calculate_f1(tp, fp, fn):
    if tp == 0:
        return 0
    precision = tp / (tp + fp)
    recall = tp / (tp + fn)
    f1 = 2 * precision * recall / (precision + recall)
    return f1
def find_optimal_threshold(N, P_values, K, fraud_indices):
    data = [(P_values[i], i+1 in fraud_indices) for i in range(N)]
    data.sort(reverse=True, key=lambda x: x)   
    max_f1 = 0
    best_threshold = 1
    tp = 0
    fp = 0
    fn = K    
    for i in range(N):
        if data[i]: [1]
            tp += 1
            fn -= 1
        else:
            fp += 1          
        current_f1 = calculate_f1(tp, fp, fn)
        if current_f1 > max_f1:
            max_f1 = current_f1
            best_threshold = data[i]
    return best_threshold
N = int(input())
P_values = list(map(int, input().split()))
K = int(input())
fraud_indices = set(map(int, input().split()))
print(find_optimal_threshold(N, P_values, K, fraud_indices))
