def calculate_f1(precision, recall):
    if precision + recall == 0:
        return 0 
    else:
        return (2 * precision * recall) / (precision + recall)


N = int(input().strip())
P = list(map(int, input().strip().split()))
K = int(input().strip())
fraud_indices = list(map(int, input().strip().split()))


fraud_set = set(fraud_indices)


scores = [(P[i], 1 if (i + 1) in fraud_set else 0) for i in range(N)]

scores.sort()


TP = FP = 0
TN = N - K
FN = K

max_f1 = -1
best_threshold = -1

previous_score = -1

for score, is_fraud in scores:
    if score != previous_score:
      
        if TP + FP > 0 and TP + FN > 0:
            precision = TP / (TP + FP)
            recall = TP / (TP + FN)
            f1 = calculate_f1(precision, recall)

            if f1 > max_f1:
                max_f1 = f1
                best_threshold = previous_score
            elif f1 == max_f1 and previous_score < best_threshold:
                best_threshold = previous_score

  
    if is_fraud:
        TP += 1
        FN -= 1
    else:
        FP += 1
        TN -= 1

    previous_score = score


if TP + FP > 0 and TP + FN > 0:
    precision = TP / (TP + FP)
    recall = TP / (TP + FN)
    f1 = calculate_f1(precision, recall)

    if f1 > max_f1:
        max_f1 = f1
        best_threshold = previous_score
    elif f1 == max_f1 and previous_score < best_threshold:
        best_threshold = previous_score

print(best_threshold)

