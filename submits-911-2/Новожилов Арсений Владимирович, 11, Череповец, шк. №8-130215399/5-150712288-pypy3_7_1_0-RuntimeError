import numpy as np

n = int(input())
p_vals = [int(x) for x in input().split()]
k = int(input())
frods = [int(x) for x in input().split()]

p_vals = np.array(p_vals)
frods = np.array(frods)
y_true = np.zeros(n, dtype=int)
for frod_idx in frods:
    y_true[frod_idx - 1] = 1

max_f1 = 0
best_t = -1

for t in range(min(p_vals), max(p_vals)):
    y_pred = (p_vals >= t).astype(int)

    tp = np.sum((y_pred == 1) & (y_true == 1))
    fp = np.sum((y_pred == 1) & (y_true == 0))
    fn = np.sum((y_pred == 0) & (y_true == 1))

    precision = tp / (tp + fp) if (tp + fp) > 0 else 0
    recall = tp / (tp + fn) if (tp + fn) > 0 else 0

    if precision + recall == 0:
        f1 = 0
    else:
        f1 = 2 * recall * precision / (recall + precision)

    if f1 > max_f1:
        best_t = t
        max_f1 = f1

print(best_t)