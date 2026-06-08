# Пример структуры входных данных (можно заменить на чтение из файла)
transactions = [
    {"user_id": 1, "amount": 1000, "ip": "192.168.1.1", "time": "08:00"},
    {"user_id": 1, "amount": 5000, "ip": "192.168.1.2", "time": "03:00"},
    {"user_id": 2, "amount": 200, "ip": "10.0.0.1", "time": "14:00"},
]

# Профили пользователей (средний чек, типичный IP)
user_profiles = {
    1: {"avg_amount": 800, "typical_ip": "192.168.1.1"},
    2: {"avg_amount": 150, "typical_ip": "10.0.0.1"},
}

# Функция для проверки транзакции
def is_fraud(transaction, profile):
    # Проверка IP
    if transaction["ip"] != profile["typical_ip"]:
        return True
    # Проверка суммы (более чем в 3 раза превышает средний чек)
    if transaction["amount"] > 3 * profile["avg_amount"]:
        return True
    # Проверка времени (ночь — с 00:00 до 06:00)
    hour = int(transaction["time"].split(":")[0])
    if 0 <= hour < 6:
        return True
    return False

# Анализ транзакций
results = []
for t in transactions:
    user_id = t["user_id"]
    profile = user_profiles.get(user_id, {})
    if is_fraud(t, profile):
        results.append(f"Транзакция {t} — ФРОД")
    else:
        results.append(f"Транзакция {t} — НЕ ФРОД")

# Вывод результатов
for result in results:
    print(result)
