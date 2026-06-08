def find_number_and_divisors(n):
  for m in range(1, 1000):
    divisors = []
    for i in range(1, m + 1):
      if m % i == 0:
        divisors.append(i)
    for i in range(1 << len(divisors)):  
      subset = []
      subset_sum = 0
      count = 0
      for j in range(len(divisors)):
        if (i >> j) & 1: 
          subset.append(divisors[j])
          subset_sum += divisors[j]
          count += 1
      if count == n and subset_sum == m and len(set(subset)) == n:  # Проверяем условия
        return m, subset
  return -1
n = int(input())
result = find_number_and_divisors(n)
if result == -1:
  print(-1)
else:
  m, divisors = result
  print(m)
  print(*divisors)