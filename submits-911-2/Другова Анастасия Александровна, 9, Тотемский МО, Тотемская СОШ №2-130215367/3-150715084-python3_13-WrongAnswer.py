def find_numbers(x, y, z):
    total_sum = 5 * z
    ab_sum = total_sum - 2 * x - y

    if abs(ab_sum) >= 2 * 10**9:
       return [-1]
  
    a = ab_sum // 2
    b = ab_sum - a

    numbers = sorted([a, b, x, x, y])
      
    if numbers.count(x) == 2 and numbers[2] == y and sum(numbers) == total_sum:
       return numbers
    else:
      return [-1]

x = int(input().strip())
y = int(input().strip())
z = int(input().strip())

result = find_numbers(x, y, z)
print(" ".join(map(str, result)))