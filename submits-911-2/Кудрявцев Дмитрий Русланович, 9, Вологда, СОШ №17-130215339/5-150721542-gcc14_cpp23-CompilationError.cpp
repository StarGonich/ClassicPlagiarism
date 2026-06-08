N = int(input())
P = list(map(int, input().split()))
K = int(input())
fraud_indices = list(map(int, input().split()))

# Создаём метки: 1 — фрод, 0 — не фрод
labels = [0] * N
for idx in fraud_indices:
    labels[idx - 1] = 1

# Объединяем оценки и метки, сортируем по P (по возрастанию)
messages = sorted(zip(P, labels), key=lambda x: x[0])

total_fraud = sum(labels)
total_non_fraud = N - total_fraud

best_F1 = -1
best_T = None

# Начальные счётчики: при T > max(P) ни одно сообщение не считается фродом
TP = 0
FP = 0
# FN = total_fraud (все фрод-сообщения пропущены)
# TN = total_non_fraud (все не-фрод правильно классифицированы)

# Перебираем возможные пороги T: каждое уникальное значение P + 1
# (чтобы T было строго больше текущего P, и текущая точка не включалась)
for i in range(N):
    P_value, label = messages[i]
    
    # Рассчитываем F1 для порога T = P_value + 1
    # (текущая точка ещё не считается фродом)
    FN = total_fraud - TP
    denom_prec = TP + FP
    denom_rec = TP + FN
    
    precision = TP / denom_prec if denom_prec > 0 else 0
    recall = TP / denom_rec if denom_rec > 0 else 0
    
    if precision == 0 and recall == 0:
        F1 = 0
    else:
        F1 = 2 * precision * recall / (precision + recall)
    
    # Обновляем лучший результат
    T = P_value + 1
    if F1 > best_F1 or (F1 == best_F1 and (best_T is None or T < best_T)):
        best_F1 = F1
        best_T = T
    
    # Теперь добавляем текущую точку в TP/FP (для следующих порогов T ≤ P_value)
    if label == 1:
        TP += 1
    else:
        FP += 1

# Отдельно проверяем порог T = min(P): все сообщения — фрод
FN = total_fraud - TP  # TP уже равно total_fraud после цикла
denom_prec = TP + FP  # FP уже равно total_non_fraud
precision = TP / denom_prec if denom_prec > 0 else 0
recall = 1.0  # все фрод-сообщения найдены
F1 = 2 * precision * recall / (precision + recall) if (precision + recall) > 0 else 0


if F1 > best_F1 or (F1 == best_F1 and (best_T is None or min(P) < best_T)):
    best_T = min(P)


print(best_T)
