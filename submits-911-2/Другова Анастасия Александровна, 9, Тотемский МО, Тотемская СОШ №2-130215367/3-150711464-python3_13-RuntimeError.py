def find_numbers(x, y, z):
    total_sum = 5 * z
    target_sum_ab = total_sum - 2 * x - y

    for a in range(-10**9, 10**9 + 1):
        b = target_sum_ab - a
      
        numbers = sorted([a, b, x, x, y])
      
        if numbers.count(x) == 2 and numbers[2] == y and sum(numbers) == total_sum:
          return numbers
    return [-1]
x = int(input().strip())
y = int(input().strip())
z = int(inpyt().strip())

result = find_numbers(x, y, z)
print(" ", join(map(str, result)))