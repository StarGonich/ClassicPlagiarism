n = int(input())  # Количество сообщений
P = list(map(int, input().split()))  # Оценки P для каждого сообщения
k = int(input())  # Количество фрод-сообщений
fraud_indices = set(map(int, input().split()))  # Номера фрод-сообщений (1-индексация)

# Переводим номера сообщений в 0-индексацию
fraud_indices = {idx - 1 for idx in fraud_indices}

# Получаем уникальные значения P (кандидаты для порога T) и сортируем их
unique_P = sorted(set(P))

best_F1 = -1
best_T = None

# Перебираем все возможные пороги T
for T in unique_P:
    # Классифицируем сообщения: P[i] >= T — фрод, иначе — не фрод
    predicted_fraud = [i for i in range(n) if P[i] >= T]

    # Вычисляем TP, FP, FN
    TP = sum(1 for idx in predicted_fraud if idx in fraud_indices)  # Верно распознанный фрод
    FP = sum(1 for idx in predicted_fraud if idx not in fraud_indices)  # Неверно распознанный фрод (не фрод, но помечен)
    FN = sum(1 for idx in fraud_indices if idx not in predicted_fraud)  # Пропущенный фрод

    # Вычисляем precision и recall
    precision = TP / (TP + FP) if (TP + FP) > 0 else 0
    recall = TP / (TP + FN) if (TP + FN) > 0 else 0

    # Вычисляем F1-метрику
    if precision + recall > 0:
        F1 = 2 * precision * recall / (precision + recall)
    else:
        F1 = 0

    # Обновляем лучший результат: ищем максимальный F1, при равенстве — минимальный T
    if F1 > best_F1 or (F1 == best_F1 and T < best_T):
        best_F1 = F1
        best_T = T

print(best_T)
