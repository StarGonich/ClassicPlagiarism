n = int(input())

m = n * (n + 1) // 2
divs = list(range(1, n + 1))
print(m)
print(' '.join(map(str, divs)))