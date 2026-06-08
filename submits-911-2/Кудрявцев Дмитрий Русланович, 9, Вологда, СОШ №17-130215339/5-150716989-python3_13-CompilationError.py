N = int(input())
P = list(map(int, input().split()))
K = int(input())
fraud_indices = list(map(int, input().split()))

# Создаем массив, где каждый элемент - (оценка, индекс, является ли фрод)
messages = []
fraud_set = set(fraud_indices) # для быстрого поиска

for i, score in enumerate(P, 1):
messages.append((score, i, i in fraud_set))

# Сортируем по оценке
messages.sort(key=lambda x: x[0])

# Подсчитаем изначальные значения:
# - Количество фрод-сообщений: total positives
total_fraud = K
total_non_fraud = N - total_fraud

# Переменные для подсчета по итогу
TP = 0
FP = 0

# Для каждого уникального значения P, попробуем вычислить F1
# Вначале, считаем, что T чуть меньше минимальной оценки (все сообщения классифицируются как не фрод)
# Тогда:
max_F1 = -1
best_T = None

# Предварительно подготовим для быстрого прохода
# Переменные для подсчета
# Изначально, при T очень маленьком, все сообщения — фрод (предположим), затем будем повышать порог.

# Изначально, все сообщения считаются фродом (T ниже минимальной оценки)
TP = total_fraud # все фрод-сообщения улучшаются
FP = total_non_fraud # все не фрод-сообщения ошибочно считаются фродом

# Посчитаем F1 с этим T
def compute_F1(TP, FP, total_fraud):
FN = total_fraud - TP
precision = TP / (TP + FP) if (TP + FP) > 0 else 0
recall = TP / (TP + FN) if (TP + FN) > 0 else 0
if precision + recall == 0:
return 0
return 2 * precision * recall / (precision + recall)

max_F1 = compute_F1(TP, FP, total_fraud)
best_T = 0 # тогда T минимально возможное

# Проходим по отсортированным сообщениям
# На каждом шаге пытаемся обновить T — взять следующую уникальную оценку
prev_score = None

for i, (score, idx, is_fraud) in enumerate(messages):
# Перед обновлением T, проверим F1
current_F1 = compute_F1(TP, FP, total_fraud)
if current_F1 > max_F1 or (current_F1 == max_F1 and (best_T is None or score < best_T)):
max_F1 = current_F1
best_T = score

# Обновляем TP и FP (если оценка равна текущему score, всё сообщение уже обработано)
# Когда увеличение порога до следующего уникального value, мы "отнимаем" от тех сообщений с такой оценкой
# ... но так как мы идем слева направо, при увеличении порога, только сообщения с равной оценкой меняются
# Можно обновлять по мере прохода
pass

# Для корректности, обновим TP и FP по мере прохождения
# Альтернативный способ: один проход, где для каждого уникального значения обновляем TP и FP
# после этого на следующем уровне.

# Для этого сделаем один проход:
TP = total_fraud
FP = total_non_fraud

# Пересчитаем для каждого уникального оценки
unique_scores = sorted(set(score for score, _, _ in messages))
current_index = 0

for T in unique_scores:
# Обновляем TP и FP для всех сообщений с оценкой <= T
# Однако, поскольку при увеличении T, сообщения с оценкой равной T становятся фродом,
# то для T, все сообщения с оценкой < T — классифицируются как не фрод
# А при T, которые равны текущему, они считаются фродом.

# Идем по сообщениям и обновляем TP, FP
# На самом деле, лучше идти по отсортированным сообщениям и на каждом шаге обновлять при смене оценки

# Перенастроим через проход:
#
# Вначале, установим T минимальным
current_F1_value = compute_F1(TP, FP, total_fraud)
if current_F1_value > max_F1 or (current_F1_value == max_F1 and (best_T is None or T < best_T)):
max_F1 = current_F1_value
best_T = T

# Однако, для более эффективного решения, реализуем один проход:
# Мы можем проходить и обновлять TP и FP при увеличении оценки

TP = 0
FP = 0

# Для сообщений заводим список по оценкам
# При проходе:
sorted_messages = sorted(messages, key=lambda x: x[0])

max_F1 = 0
best_T = None

# Изначально, T очень маленькое, все сообщения считаются фродом
TP = total_fraud
FP = total_non_fraud
current_score_value = -1

# Идем по отсортированным сообщениям
prev_score = -1
for i, (score, idx, is_fraud) in enumerate(sorted_messages):
# Перед обработкой нового score, считаем F1
F1_current = compute_F1(TP, FP, total_fraud)
if F1_current > max_F1 or (F1_current == max_F1 and (best_T is None or score < best_T)):
max_F1 = F1_current
best_T = score

# Обновляем TP и FP для сообщений с этим же score
# После этого, для следующего шага, порог будет равно следующему уникальному score
# пока счетчик не будет увеличен до следующего score
while i < len(sorted_messages) and sorted_messages[i][0] == score:
_, _, is_fraud = sorted_messages[i]
if is_fraud:
TP -= 1
else:
FP -= 1
i += 1
# И так как в цикле i увеличился, надо скорректировать i обратно
# поскольку внешний цикл уже увеличит i, исправим:
i -= 1 # чтобы следующий проход корректно работал

# Итог: ответ - лучший T (самое маленькое среди равных максимально F1)

print(best_T)