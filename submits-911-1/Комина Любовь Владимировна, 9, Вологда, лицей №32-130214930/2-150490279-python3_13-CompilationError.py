n = int(input())
if n==1:
print(1)
print(1)
else:
m = 2 ** (n-1) * 3
print(m)
d = [2 ** i for i in range(n - 1)] + [m // 2 ** (n - 2)]
print(*d)