def solve():
    n = int(input())

    for m in range(1, 1001):
        divisors = []
        for i in range(1, m + 1):
            if m % i == 0:
                divisors.append(i)

        if len(divisors) - 1 < n:
            continue

        from itertools import combinations

        for subset in combinations(divisors, n):
            if sum(subset) == m:
                print(m)
                print(*subset)
                return

    print("-1")

solve()