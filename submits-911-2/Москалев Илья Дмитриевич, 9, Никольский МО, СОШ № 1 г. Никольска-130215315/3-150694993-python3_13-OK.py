x = int(input())
y = int(input())
z = int(input())

def solve():
    total_sum = 5 * z

    # Случай 1: x == y
    if x == y:
        # Пробуем a = x, тогда массив: [x, b, x, d, e]
        # Нужно: b + d + e = 5z - 2x
        target = 5*z - 2*x

        # Подбираем b и d, не равные x
        for b in [x+1, x-1, x+2, x-2]:
            if b == x:
                continue
            for d in [x+1, x-1, x+2, x-2]:
                if d == x or d == b:
                    continue
                e = target - b - d
                # Проверяем, что e не равно x, b, d и в диапазоне
                if e == x or e == b or e == d:
                    continue
                if -10**9 <= e <= 10**9:
                    arr = [x, b, x, d, e]
                    arr.sort()  # для проверки медианы (должно остаться y=x на позиции 2)
                    if arr[2] == x:
                        return arr
        return -1

    # Случай 2: x != y
    else:
        # Пробуем a = x, b = x, массив: [x, x, y, d, e]
        # Нужно: d + e = 5z - 2x - y
        target = 5*z - 2*x - y

        # Подбираем d, не равное x и y
        for d in [x+1, x-1, y+1, y-1, 0]:
            if d == x or d == y:
                continue
            e = target - d
            # Проверяем, что e не равно x, y, d и в диапазоне
            if e == x or e == y or e == d:
                continue
            if -10**9 <= e <= 10**9:
                arr = [x, x, y, d, e]
                arr.sort()
                if arr[2] == y:
                    return arr
        return -1

result = solve()
if result == -1:
    print(-1)
else:
    print(' '.join(map(str, result)))