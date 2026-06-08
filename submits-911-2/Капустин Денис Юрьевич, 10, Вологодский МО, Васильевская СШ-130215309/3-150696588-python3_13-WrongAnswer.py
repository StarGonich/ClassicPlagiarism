x = int(input())
y = int(input())
z = int(input())
if x == y:
    print(-1)
else:
    numbers = [-1] * 5
    numbers[1] = numbers[3] = x
    numbers[2] = y
    sum_remaining = 5 * z - 2 * x - y
    a = 0
    b = sum_remaining - a
    if b == x or b == y or a == y:
      print(-1)
    else:
      numbers[0] = a
      numbers[4] = b
      print(*numbers)