def sum_divisors(n):
    """Вычисляет сумму делителей числа n."""
    divisors = []
    for i in range(1, n):
        if n % i == 0:
            divisors.append(i)
    return divisors

def solve():
    """Решает задачу о сумме делителей."""
    n = int(input())
    for m in range(1, 10**9 + 1):
        divisors = sum_divisors(m)
        if len(divisors) >= n:
            if sum(sorted(divisors, reverse=True)[:n]) == m:
                print(m)
                print(*sorted(divisors, reverse=True)[:n])
                return
    print(-1)

solve()