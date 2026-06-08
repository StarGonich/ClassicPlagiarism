def is_beautiful_time(h, m):
    # Преобразуем часы и минуты в строку, чтобы легко сравнивать их
    h_str = f"{h:02}"
    m_str = f"{m:02}"
    
    # Условие 1: Часы и минуты одинаковые
    if h_str == m_str:
        return True
    
    # Условие 2: Часы и минуты зеркальные
    if h_str == m_str[::-1]:
        return True
    
    # Условие 3: Последовательные цифры
    digits = h_str + m_str  # объединяем часы и минуты в одну строку
    # Проверяем, идут ли цифры по порядку
    if all(int(digits[i]) == int(digits[i-1]) + 1 for i in range(1, len(digits))):
        return True
    
    return False

def count_beautiful_times(h1, m1, h2, m2):
    count = 0
    # Преобразуем начальное и конечное время в минуты с начала дня
    start_minutes = h1 * 60 + m1
    end_minutes = h2 * 60 + m2
    
    # Перебираем все возможные моменты времени от start_minutes до end_minutes включительно
    for total_minutes in range(start_minutes, end_minutes + 1):
        h = total_minutes // 60
        m = total_minutes % 60
        if is_beautiful_time(h, m):
            count += 1
    
    return count

# Ввод данных
h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

# Подсчитаем количество красивых моментов времени
result = count_beautiful_times(h1, m1, h2, m2)

# Вывод результата
print(result)
