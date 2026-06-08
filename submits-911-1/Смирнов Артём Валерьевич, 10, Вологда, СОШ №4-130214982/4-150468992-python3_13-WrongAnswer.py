import math
import sys

n = int(sys.stdin.readline())
k = int(sys.stdin.readline())

# Диапазон p
left = n + 1
right = n + k

# Функция для поиска делителей числа
def get_divisors(x):
    divs = set()
    limit = int(math.isqrt(x))
    for i in range(1, limit + 1):
        if x % i == 0:
            divs.add(i)
            divs.add(x // i)
    return divs

min_lcm = None
result_p = None

# Проверка делителей n
for d in get_divisors(n):
    candidates = [d, n // d]
    for p_candidate in candidates:
        if left <= p_candidate <= right:
            # Вычисляем НОК
            g = math.gcd(n, p_candidate)
            lcm = (n // g) * p_candidate
            if min_lcm is None or lcm < min_lcm:
                min_lcm = lcm
                result_p = p_candidate

# Также проверить крайние точки диапазона, так как они могут дать меньший НОК
# Проверим в диапазоне n+1..n+k и выберем минимальный НОК
# Но так как диапазон может быть очень большим, лучше проверить только пару наиболее вероятных вариантов
# В данном случае, проверим только крайние точки, так как внутри диапазона, где p не делит n, НОК будет больше.

# Вариант 1 - p = n+1
g = math.gcd(n, left)
lcm = (n // g) * left
if min_lcm is None or lcm < min_lcm:
    min_lcm = lcm
    result_p = left

# Вариант 2 - p = n+k
g = math.gcd(n, right)
lcm = (n // g) * right
if min_lcm is None or lcm < min_lcm:
    min_lcm = lcm
    result_p = right

print(result_p)