n = 10**9
total = 0
total1 = 0
for i in range(1, n + 1):
    print(i, end='')
    for j in range(1, i + 1):
        if i % j == 0:
            total += 1
        print('+' * total1, end='')
    print()