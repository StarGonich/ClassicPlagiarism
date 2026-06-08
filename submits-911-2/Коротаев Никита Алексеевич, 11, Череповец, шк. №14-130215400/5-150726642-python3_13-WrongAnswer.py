def calculate_f1(precision, recall):
    if precision + recall > 0:
        return 2 * precision * recall / (precision + recall)
    else:
        return 0
n = int(input())
scores = list(map(int, input().split()))
k = int(input())
fraud = set(map(int, input().split()))
def count_metrics(threshold):
    true_positives = sum(1 for i in range(n) if scores[i] >= threshold and (i+1) in fraud)
    false_positives = sum(1 for i in range(n) if scores[i] >= threshold and (i+1) not in fraud)
    true_negatives = sum(1 for i in range(n) if scores[i] < threshold and (i+1) not in fraud)
    false_negatives = k - true_positives
    
    return true_positives, false_positives, true_negatives, false_negatives
best_threshold = None
max_f1_score = -float('inf')
unique_scores = sorted(set(scores))

for score in unique_scores:
    tp, fp, tn, fn = count_metrics(score)
    precision = tp / (tp + fp) if (tp + fp) != 0 else 0
    recall = tp / (tp + fn) if (tp + fn) != 0 else 0
    f1 = calculate_f1(precision, recall)
    
    if f1 > max_f1_score or (f1 == max_f1_score and best_threshold is None):
        max_f1_score = f1
        best_threshold = score

print(best_threshold)