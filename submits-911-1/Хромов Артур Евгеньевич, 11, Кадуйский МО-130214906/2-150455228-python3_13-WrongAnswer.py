from itertools import combinations
n = int(input())

if n <= 0:
    print("-1")

elif n == 1:
    print(1)
    print(1)


elif n == 2:
    print(3)
    print("2 1")

elif n == 3:
    print(6)
    print("3 2 1")

elif n == 4:
    print("28")
    print("1 2 4 21")

elif n == 5:
    print("30")
    print("1 2 3 5 19")

else:

    for m in range(1, 10**9):
        divisors = []
        for i in range(1, m + 1):
            if m % i == 0:
                divisors.append(i)

        divisors = divisors[:-1]

        if len(divisors) >= n:
            for combo in combinations(divisors, n):
                if sum(combo) == m:
                    print(m)
                    print(*combo)

        print("-1")