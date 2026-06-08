n = int(input())

if n == 1:
    print(1)
    print(1)
    exit()# умно

m = n * (n + 1) // 2
sum_of_first_n_minus_1 = (n - 1) * n // 2
d = m - sum_of_first_n_minus_1

if d <= n and m % d == 0:
    print(m)
    divs = list(range(1, n))
    divs.append(d)
    print(" ".join(map(str, divs)))
else:
    print(-1)