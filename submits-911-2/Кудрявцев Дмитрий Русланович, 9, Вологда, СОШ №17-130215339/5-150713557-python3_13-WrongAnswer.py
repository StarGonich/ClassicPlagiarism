import sys

# Считываем входные данные
N = int(input())  # Количество сообщений
P = list(map(int, input().split()))  # Оценки P для каждого сообщения
K = int(input())  # Количество фрод-сообщений
fraud_indices = set(map(int, input().split()))  # Индексы фрод-сообщений (1-индексация)

# Переводим индексы в 0-индексацию
fraud_indices = {idx - 1 for idx in fraud_indices}

# Находим все уникальные оценки P (кандидаты для порога T)
unique_P = sorted(set(P))

best_F1 = -1
best_T = None

# Перебираем все возможные пороги T
for T in unique_P:
    # Классифицируем сообщения по порогу T
    predicted_fraud = [i for i in range(N) if P[i] >= T]  # Индексы сообщений, признанных фродом

    # Вычисляем TP, FP, TN, FN
    TP = sum(1 for idx in predicted_fraud if idx in fraud_indices)  # Верно распознанный фрод
    FP = sum(1 for idx in predicted_fraud if idx not in fraud_indices)  # Неверно распознанный фрод (не фрод, но помечен)
    FN = sum(1 for idx in fraud_indices if idx not in predicted_fraud)  # Пропущенный фрод
    TN = N - TP - FP - FN  # Верно распознанные не-фрод сообщения

    # Вычисляем precision и recall
    if TP + FP > 0:
        precision = TP / (TP + FP)
    else:
        precision = 0

    if TP + FN > 0:
        recall = TP / (TP + FN)
    else:
        recall = 0

    # Вычисляем F1
    if precision + recall > 0:
        F1 = 2 * precision * recall / (precision + recall)
    else:
        F1 = 0

    # Обновляем лучший результат
    if F1 > best_F1 or (F1 == best_F1 and T < best_T):
        best_F1 = F1
        best_T = T

print(best_T)
