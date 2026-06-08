def solve():
    n = int(input())

    for m in range(1, 1001):  # Оптимизация: перебираем только небольшие числа
        divisors = []
        for i in range(1, m + 1):
            if m % i == 0:
                divisors.append(i)

        if len(divisors) - 1 < n : # Оптимизация: очевидно, что в этом случае точно не получится
            continue

        for i in range(1 << len(divisors)): # Перебор всех подмножеств делителей
            subset = []
            subset_sum = 0
            count = 0
            for j in range(len(divisors)):
                if (i >> j) & 1:
                    subset.append(divisors[j])
                    subset_sum += divisors[j]
                    count += 1

            if count == n and subset_sum == m:
                print(m)
                print(*subset)
                return

    print("-1") # Если не найдено подходящего ответа

solve()