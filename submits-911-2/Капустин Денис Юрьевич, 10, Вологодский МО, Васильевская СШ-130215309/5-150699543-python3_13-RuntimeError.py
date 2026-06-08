N = ...
P = [...]
K = ...
fraud_indices = set(...)
messages = [(P[i], i+1) for i in range(N)]
messages.sort(key=lambda x: x[0])
values = sorted(set(P))
max_F1 = -1
best_T = 1
for t in values:
    idx = bisect_left(messages, (t, -1))
    subset = messages[idx:]
    TP = sum(1 for _, i in subset if i in fraud_indices)
    FP = sum(1 for _, i in subset if i not in fraud_indices)
    precision = TP / (TP + FP) if (TP + FP) > 0 else 0
    recall = TP / K
    F1 = (2 * precision * recall) / (precision + recall) if (precision + recall) > 0 else 0
    if F1 > max_F1 or (F1 == max_F1 and t < best_T):
        max_F1 = F1
        best_T = t
print(best_T)