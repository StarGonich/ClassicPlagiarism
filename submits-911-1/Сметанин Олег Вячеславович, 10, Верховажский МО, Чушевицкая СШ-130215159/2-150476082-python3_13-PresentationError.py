def get_divisors(n):
    divisors = set()
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            divisors.add(i)
            divisors.add(n // i)
    return sorted(divisors)

def can_sum_to_n(divisors, target):
    n = len(divisors)
    dp = [False] * (target + 1)
    dp[0] = True  

    for div in divisors:
        for j in range(target, div - 1, -1):
            if dp[j - div]:
                dp[j] = True

    return dp[target]

def find_numbers(limit):
    results = []
    for n in range(1, limit + 1):
        divisors = get_divisors(n)
        if can_sum_to_n(divisors, n):
            results.append(n)
    return results