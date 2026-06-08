N = int(input())
messages = []
for _ in range(N):
    P, label = input().split()
    P = float(P)
    label = label.strip()
    messages.append((P, label))
thresholds = sorted(set(P for P, _ in messages))
best_T = None
best_F1 = -1
for T in thresholds:
    TP = FP = TN = FN = 0
    for P, label in messages:
        pred_fraud = (P >= T)
        actual_fraud = (label == 'fraud')
        if pred_fraud and actual_fraud:
            TP += 1
        elif pred_fraud and not actual_fraud:
            FP += 1
        elif not pred_fraud and not actual_fraud:
            TN += 1
        elif not pred_fraud and actual_fraud:
            FN += 1
    precision = TP / (TP + FP) if (TP + FP) > 0 else 0
    recall = TP / (TP + FN) if (TP + FN) > 0 else 0
    if precision + recall == 0:
        F1 = 0
    else:
        F1 = 2 * precision * recall / (precision + recall)
    if F1 > best_F1:
        best_F1 = F1
        best_T = T
print(best_T)