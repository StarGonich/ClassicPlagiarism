import sys
input = sys.stdin.read
data = input().split()
index = 0
N = int(data[index])
index += 1
P = [int(data[index + i]) for i in range(N)]
index += N
K = int(data[index])
index += 1
fraud_indices = [int(data[index + i]) - 1 for i in range(K)]  
is_fraud = [False] * N
for idx in fraud_indices:
    is_fraud[idx] = True
max_p = max(P) if P else 1
best_t = max_p + 1
i = 0
while i < N:
    current_p = messages[i][0]
    count_fraud = 0
    count_non = 0
    j = i
    while j < N and messages[j][0] == current_p:
        if messages[j][1]:
            count_fraud += 1
        else:
            count_non += 1
        j += 1
    
    TP += count_fraud
    FP += count_non
    FN -= count_fraud
    TN -= count_non
   
    current_t = current_p
   
    if TP + FP > 0:
        precision = TP / (TP + FP)
     else:
    precision = 0.0
    if TP + FN > 0:
        recall = TP / (TP + FN)
    else:
        recall = 0.0
    if precision + recall > 0:
        f1 = 2 * precision * recall / (precision + recall)
    else:
        f1 = 0.0
    
    if f1 > max_f1 or (abs(f1 - max_f1) < 1e-9 and current_t < best_t):
        max_f1 = f1
        best_t = current_t
    i = j
print(int(best_t))