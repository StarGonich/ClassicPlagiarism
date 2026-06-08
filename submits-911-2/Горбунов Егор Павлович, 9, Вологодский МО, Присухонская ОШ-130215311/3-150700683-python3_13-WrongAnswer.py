def find_numbers(x, y, z):
    if x > y or x > z:
        return -1
    
    sum_needed = 5 * z 
    current_sum = 2 * x + y 
    remaining_sum = sum_needed - current_sum  
    for a in range(-100, 101):
        b = remaining_sum - a
        if -100 <= b <= 100:
            if a != x and b != x and a != b:
                return [x, x, y, a, b]
    
    return -1

x = int(input())
y = int(input())
z = int(input())

result = find_numbers(x, y, z)
if result == -1:
    print(-1)
else:
    print(*sorted(result))
