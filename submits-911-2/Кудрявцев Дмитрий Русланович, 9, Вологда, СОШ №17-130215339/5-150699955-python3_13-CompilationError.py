# Считываем входные данные
N = int(input())  # Количество сообщений
K = int(input())  # Количество фрод-сообщений
messages = [int(input()) for _ in range(N)]  # Список значений сообщений

# Считываем индексы фрод-сообщений (индексы в задаче с 1, в Python — с 0)
fraud_indices = []
for _ in range(K):
    fraud_index = int(input()) - 1
    fraud_indices.append(fraud_index)

# Вычисляем порог T — среднее арифметическое значений фрод-сообщений
fraud_values = [messages[i] for i in fraud_indices]
T = sum(fraud_values) / len(fraud_values)

# Классифицируем все сообщения
for i, message in enumerate(messages):
    if message >= T:
        print(f"Сообщение {i+1} — ФРОД")  # +1 для соответствия нумерации в задаче
    else:
        print(f"Сообщение {i+1} — НЕ ФРОД")
Сообщение 1 — ФРОД
Сообщение 2 — НЕ ФРОД
Сообщение 3 — ФРОД
Сообщение 4 — ФРОД
Сообщение 5 — ФРОД
