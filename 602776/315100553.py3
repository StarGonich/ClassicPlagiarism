from math import lcm

n = int(input())

div = {lcm(4, 6), lcm(4, 5), lcm(5, 6)}

ans = n // 4 + n // 5 + n // 6 - 2 * (n // 12 + n // 20 + n // 30)

print(ans)
