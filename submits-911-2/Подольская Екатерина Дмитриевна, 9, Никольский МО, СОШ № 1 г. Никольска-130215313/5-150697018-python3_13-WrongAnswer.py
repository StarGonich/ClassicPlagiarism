def find_best_threshold(N, scores, K, fraud_indices):
    # Преобразуем входные данные
    fraud_set = set(fraud_indices)
    messages = list(enumerate(scores, start=1))
    
    # Сортируем по убыванию оценки
    messages.sort(key=lambda x: x[1], reverse=True)
    
    # Общее число фрод-сообщений
    total_fraud = K
    total_non_fraud = N - total_fraud
    
    # Счетчики
    TP = 0
    FP = 0
    FN = total_fraud
    TN = total_non_fraud
    
    max_F1 = -1
    best_T = None
    
    # Проходим по отсортированным сообщениям
    for i, (idx, p) in enumerate(messages):
        # Обновляем счетчики
        if idx in fraud_set:
            TP += 1
            FN -= 1
        else:
            FP += 1
            TN -= 1
        
        # Текущий порог — равен текущему оценке P (или чуть меньше, чтобы включить сообщения с P >= p)
        T = p
        
        # Вычисляем precision и recall
        if TP + FP == 0:
            precision = 0
        else:
            precision = TP / (TP + FP)
        
        if TP + FN == 0:
            recall = 0
        else:
            recall = TP / (TP + FN)
        
        # Вычисляем F1
        if precision + recall == 0:
            F1 = 0
        else:
            F1 = 2 * precision * recall / (precision + recall)
        
        # Обновляем максимум
        if F1 > max_F1:
            max_F1 = F1
            best_T = T
    
    return best_T