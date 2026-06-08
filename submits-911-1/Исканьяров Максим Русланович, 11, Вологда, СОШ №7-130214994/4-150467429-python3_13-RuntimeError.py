n, k = map(int, input().split())

best_d = 1
for i in range(1, int(n**0.5) + 1):
    if n % i == 0:
        if i <= k:
            best_d = max(best_d, i)
        if n // i <= k:
            best_d = max(best_d, n // i)

print(n + best_d)
