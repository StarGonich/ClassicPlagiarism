import math
n = int(input())
ans = ''
f = math.factorial(n)
print(f)
for i in range(1, n + 1):
    ans += str(i) + ' '
print(ans)