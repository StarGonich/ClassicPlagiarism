n = int(input())
scores = list(map(int, input().split()))
k = int(input())
spam_indices = set(map(int, input().split()))

messages = []
for i in range(n):
    is_spam = 1 if (i + 1) in spam_indices else 0
    messages.append((scores[i], is_spam))

messages.sort(reverse=True)

thresholds = sorted(set(scores), reverse=True)
thresholds.append(0)  
thresholds = [t + 1 for t in thresholds]  
thresholds.append(1) 
thresholds = sorted(set(thresholds))

best_F1 = -1
best_T = 1

for T in thresholds:
    TP = FP = FN = 0
    for score, is_spam in messages:
        predicted_spam = 1 if score >= T else 0
        if predicted_spam == 1 and is_spam == 1:
            TP += 1
        elif predicted_spam == 1 and is_spam == 0:
            FP += 1
        elif predicted_spam == 0 and is_spam == 1:
            FN += 1
    
    if TP + FP == 0:
        precision = 0
    else:
        precision = TP / (TP + FP)
    
    if TP + FN == 0:
        recall = 0
    else:
        recall = TP / (TP + FN)
    
    if precision + recall == 0:
        F1 = 0
    else:
        F1 = 2 * precision * recall / (precision + recall)
    
    if F1 > best_F1 or (F1 == best_F1 and T < best_T):
        best_F1 = F1
        best_T = T

print(best_T)