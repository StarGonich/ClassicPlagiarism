import math

n = int(input())
k = int(input())

# Функция для поиска делителей числа n
def get_divisors(x):
    divs = set()
    limit = int(math.isqrt(x))
    for i in range(1, limit + 1):
        if x % i == 0:
            divs.add(i)
            divs.add(x // i)
    return divs

divisors = get_divisors(n)

min_lcm = None
answer_p = -1

for d in divisors: