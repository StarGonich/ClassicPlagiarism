n = int(input())
p = list(map(int, input().split()))
k = int(input())
fraud_indices = list(map(int, input().split()))

# Создаём массив: is_fraud[i] = True, если сообщение i — фрод (индексация с 1)
is_fraud = [False] * (n + 1)
for idx in fraud_indices:
    is_fraud[idx] = True

# Список пар (оценка, является ли фродом)
messages = [(p[i], is_fraud[i + 1]) for i in range(n)]

# Сортируем по оценке P (для бинарного поиска)
messages.sort()

# Все уникальные пороги T — это уникальные значения P
thresholds = sorted(set(p))


best_f1 = -1
best_t = None

for t in thresholds:
    tp = fp = fn = tn = 0
    for pi, is_f in messages:
        if pi >= t:
            if is_f:
                tp += 1
            else:
                fp += 1
        else:
            if is_f:
                fn += 1
            else:
                tn += 1

    # Вычисляем precision и recall
    if tp + fp == 0:
        precision = 0.0
    else:
        precision = tp / (tp + fp)

    if tp + fn == 0:
        recall = 0.0
    else:
        recall = tp / (tp + fn)

    # Вычисляем F1
    if precision == 0 and recall == 0:
        f1 = 0.0
    else:
        f1 = 2 * precision * recall / (precision + recall)

    # Обновляем лучший порог
    if f1 > best_f1 or (f1 == best_f1 and t < best_t):
        best_f1 = f1
        best_t = t

print(best_t)