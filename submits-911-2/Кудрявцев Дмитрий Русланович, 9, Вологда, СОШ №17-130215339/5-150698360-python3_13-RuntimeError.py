# Считываем входные данные
N = int(input())  # Общее количество сообщений
K = int(input())  # Количество фрод-сообщений
messages = [int(input()) for _ in range(N)]  # Список сообщений (числа от 1 до 70)

# Создаем список для отметки фрод-сообщений (False — не фрод, True — фрод)
is_fraud = [False] * N

# Отмечаем K фрод-сообщений (индексы сообщений, которые являются фродом)
fraud_indices = []
for _ in range(K):
    fraud_index = int(input()) - 1  # Индексы в Python начинаются с 0
    fraud_indices.append(fraud_index)
    is_fraud[fraud_index] = True

# Вычисляем порог T — среднее арифметическое фрод-сообщений
fraud_values = [messages[i] for i in fraud_indices]
T = sum(fraud_values) / len(fraud_values)

# Выводим результаты
print(f"Порог T: {T}")

# Проверяем каждое сообщение: если значение >= T, считаем фродом
for i, message in enumerate(messages):
    if message >= T:
        print(f"Сообщение {i+1} (значение: {message}) — ФРОД")
    else:
        print(f"Сообщение {i+1} (значение: {message}) — НЕ ФРОД")
