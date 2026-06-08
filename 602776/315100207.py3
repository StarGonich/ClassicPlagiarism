n = int(input())
r = n // 4 + n // 5 + n // 6
r -= (n // 12) * 2 + (n // 20) * 2 + (n // 30) * 2
r += (n // 60) * 3
print(r)
