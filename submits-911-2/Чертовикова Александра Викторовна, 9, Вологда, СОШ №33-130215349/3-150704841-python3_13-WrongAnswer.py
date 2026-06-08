def find_numbers(x, y, z):
    # Считаем требуемую сумму
    required_sum = 5 * z

    # Пятый элемент
    p = required_sum - (3 * x + y)

    # Проверяем, чтобы медиана была y
    # Мода равна x, медиана равна y и p должен быть выбрана таким образом, чтобы все условия выполнялись.
    if p < -10**9 or p > 10**9:
        return -1
    
    # Теперь мы проверяем условия:
    # 1. x должен встречаться 3 раза
    # 2. медиана должна быть равна y
    # 3. p должен быть в допустимых границах
    if (3 * x + y + p) % 5 == 0 and p != x:
        return [x, x, x, y, p]
    else:
        return -1

# Чтение входа x, y, z
x = int(input().strip())
y = int(input().strip())
z = int(input().strip())

result = find_numbers(x, y, z)

if result == -1:
    print(-1)
else:
    print(" ".join(map(str, result)))

