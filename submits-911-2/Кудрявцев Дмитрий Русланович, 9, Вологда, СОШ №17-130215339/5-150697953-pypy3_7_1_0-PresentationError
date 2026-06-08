# Входные данные: список транзакций и профили пользователей
transactions = [
    {"user_id": 1, "amount": 1000, "ip": "192.168.1.1", "time": "08:00"},
    {"user_id": 1, "amount": 5000, "ip": "192.168.1.2", "time": "03:00"},
    {"user_id": 2, "amount": 200, "ip": "10.0.0.1", "time": "14:00"}
]

user_profiles = {
    1: {"avg_amount": 800, "typical_ip": "192.168.1.1"},
    2: {"avg_amount": 150, "typical_ip": "10.0.0.1"}
}

# Функция для проверки, является ли транзакция подозрительной (фрод)
def is_fraud(transaction, profile):
    # Проверка IP-адреса: отличается ли от типичного для пользователя?
    if transaction["ip"] != profile["typical_ip"]:
        return True
    
    # Проверка суммы: превышает ли в 3 раза средний чек?
    if transaction["amount"] > 3 * profile["avg_amount"]:
        return True
    
    # Проверка времени: совершена ли транзакция ночью (00:00–06:00)?
    hour = int(transaction["time"].split(":")[0])  # Извлекаем час из строки времени
    if 0 <= hour < 6:
        return True
    
    # Если ни одно из условий не сработало — транзакция не подозрительная
    return False

# Основной цикл: анализ каждой транзакции
for transaction in transactions:
    user_id = transaction["user_id"]
    profile = user_profiles.get(user_id)  # Получаем профиль пользователя
    
    if profile is None:
        print(f"Профиль пользователя {user_id} не найден!")
        continue  # Пропускаем транзакцию, если профиль не найден
    
    # Проверяем, является ли транзакция фродом
    if is_fraud(transaction, profile):
        print(f"Транзакция пользователя {user_id} (сумма: {transaction['amount']}, "
              f"IP: {transaction['ip']}, время: {transaction['time']}) — ФРОД")
    else:
        print(f"Транзакция пользователя {user_id} (сумма: {transaction['amount']}, "
              f"IP: {transaction['ip']}, время: {transaction['time']}) — НЕ ФРОД")
