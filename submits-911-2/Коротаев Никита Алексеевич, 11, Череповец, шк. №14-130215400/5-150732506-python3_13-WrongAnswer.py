def calculate_f1(precision, recall):
    if precision + recall > 0:
        return 2 * precision * recall / (precision + recall)
    else:
        return 0

n = int(input())
scores = list(map(int, input().split()))
k = int(input())
fraud = set(map(int, input().split()))

best_threshold = None
max_f1_score = 0

for t in sorted(set(scores)):  
    true_positives = sum(1 for i in range(n) if scores[i] >= t and (i + 1) in fraud)
    false_positives = sum(1 for i in range(n) if scores[i] >= t and (i + 1) not in fraud)
    true_negatives = sum(1 for i in range(n) if scores[i] < t and (i + 1) not in fraud)
    false_negatives = k - true_positives
    
    precision = true_positives / (true_positives + false_positives) if (true_positives + false_positives) > 0 else 0
    recall = true_positives / (true_positives + false_negatives) if (true_positives + false_negatives) > 0 else 0
    f1 = calculate_f1(precision, recall)
    
    if f1 > max_f1_score or (f1 == max_f1_score and best_threshold is None):
        max_f1_score = f1
        best_threshold = t

print(best_threshold)