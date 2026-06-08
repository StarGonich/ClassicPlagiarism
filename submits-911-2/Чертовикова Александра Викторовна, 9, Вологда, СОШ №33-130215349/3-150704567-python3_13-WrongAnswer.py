def find_numbers(x, y, z):
    required_sum = 5 * z
    p = required_sum - (3 * x + y)

  
    if p < -10**9 or p > 10**9:
        return -1
    
    if (3 * x + y + p) % 5 == 0 and p != x:
        return [x, x, x, y, p]
    else:
        return -1

x = int(input().strip())
y = int(input().strip())
z = int(input().strip())

result = find_numbers(x, y, z)

if result == -1:
    print(-1)
else:
    print(" ".join(map(str, result)))
