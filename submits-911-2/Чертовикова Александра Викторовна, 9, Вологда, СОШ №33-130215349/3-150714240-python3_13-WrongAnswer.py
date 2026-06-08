def find_numbers(x, y, z):
    
    total_needed = 5 * z - 2 * x - y
    
   
    if total_needed % 2 != 0:
        return [-1]

    k = total_needed // 2

 
    if -10**9 <= x <= 10**9 and -10**9 <= k <= 10**9 and -10**9 <= y <= 10**9:
        return [x, x, y, k, k]
    else:
        return [-1]


x = int(input())
y = int(input())
z = int(input())


result = find_numbers(x, y, z)


print(' '.join(map(str, result)))

