def solve():
    n = int(input())

    m = n * (n + 1)

    if m > 10**9:
      print(-1)
      return

    divisors = list(range(1, n + 1)) # 1, 2, ..., n
    divisors.append(n * (n + 1) // 2) # n(n+1) / 2

    if len(set(divisors)) == n + 1:
      print(m)
      print(*divisors)
    else:
        print(-1)

solve()