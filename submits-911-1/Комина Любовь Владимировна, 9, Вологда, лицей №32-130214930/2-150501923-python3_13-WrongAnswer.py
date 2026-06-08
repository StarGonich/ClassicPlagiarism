n = int(input())

if n == 1:
    print(1)
    print(1)
elif n == 2:
    print(6)
    print("3 2 1")
else:
    result = 2 ** (n - 1) * 3
    divisors = [2 ** i for i in range(n - 1)] + [result // 2]
    print(result)
    print(' '.join(map(str, divisors)))