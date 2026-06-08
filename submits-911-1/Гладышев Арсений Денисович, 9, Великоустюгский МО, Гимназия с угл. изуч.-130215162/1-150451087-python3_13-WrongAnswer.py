# Функция проверки одинаковых значений
def is_same(hours, minutes):
    return hours == minutes

# Функция проверки зеркальных значений
def is_mirror(hours, minutes):
    return str(hours)[::-1] == str(minutes).zfill(2)

# Функция проверки последовательности цифр
def is_sequence(hours, minutes):
    time_str = f"{hours:02d}{minutes:02d}" # дополняем нулями до двух знаков
    for i in range(len(time_str)-1):
        if int(time_str[i+1]) != int(time_str[i]) + 1:
            return False
    return True

# Основная функция подсчета красивых моментов времени
def count_beautiful_times(start_h, start_m, end_h, end_m):
    beautiful_count = 0
    
    current_h = start_h
    current_m = start_m
    
    while True:
        # Проверяем условия красоты времени
        if is_same(current_h, current_m) or \
           is_mirror(current_h, current_m) or \
           is_sequence(current_h, current_m):
            beautiful_count += 1
            
        # Переход к следующему моменту времени
        current_m += 1
        if current_m >= 60:
            current_m = 0
            current_h += 1
            if current_h > 23:
                break
                
        # Остановка цикла, если достигли конечного времени
        if current_h > end_h or (current_h == end_h and current_m > end_m):
            break
            
    return beautiful_count

# Читаем входные данные
start_h = int(input())  # начальные часы
start_m = int(input())  # начальные минуты
end_h   = int(input())  # конечные часы
end_m   = int(input())  # конечные минуты

# Получаем итоговый результат
result = count_beautiful_times(start_h, start_m, end_h, end_m)

# Выводим результат
print(result)