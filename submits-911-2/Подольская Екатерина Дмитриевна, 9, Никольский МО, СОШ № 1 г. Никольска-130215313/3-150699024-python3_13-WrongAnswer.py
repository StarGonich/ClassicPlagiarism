x = int(input())
y = int(input())
z = int(input())

# Общее целевое суммарное значение
total_sum = 5 * z

# Вариант 1: возьмем мод = x, и сделаем так, чтобы x встречался 3 раза
#   и гарантируем, что мода уникальна, т.к. остальные числа не встречаются чаще
# Тогда три числа = x, остальные два — подберем по сумме

# Пусть:
# три раза x
sum_x = 3 * x

# Тогда оставшиеся два числа должны дать сумму:
rest_sum = total_sum - sum_x

# Выбираем d и e равными, чтобы сумма была равна rest_sum
# d = e = rest_sum // 2 (если делится на 2)
if rest_sum % 2 != 0:
    # Делим так, чтобы остаться в диапазоне
    # чуть добавляем или убираем единицу
    # Например, можно сделать:
    d = rest_sum // 2
    e = rest_sum - d
else:
    d = e = rest_sum // 2

# Теперь составим список и отсортируем
numbers = [x, x, x, d, e]
numbers.sort()

# Проверка:
median = numbers[2]
counts = {}
for num in numbers:
    counts[num] = counts.get(num, 0) + 1
max_count = max(counts.values())

# Мода — число с максимальной частотой
modes = [k for k, v in counts.items() if v == max_count]

# Условие: мод = x и единственная
if len(modes) == 1 and modes[0] == x:
    # Проверяем, что все в диапазоне
    if all(-10**9 <= num <= 10**9 for num in numbers):
        # Проверяем условие медианы и среднего
        if median == y and sum(numbers) == total_sum:
            print(' '.join(map(str, numbers)))
            exit(0)
# Если не выполнены условия — выводим -1.
print(-1)