n = int(input())
if n == 1:
   print(1)
   print(1)
elif n == 2:
   print(-1)
s = ['1', '2', '3']
k = 6
for i in range(3, n, 1):
   k = k * 2
   s += [k // 2]
print(k)
print(*s)