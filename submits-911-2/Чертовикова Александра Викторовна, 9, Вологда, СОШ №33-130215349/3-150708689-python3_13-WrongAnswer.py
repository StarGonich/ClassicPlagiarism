def find_set(x, y, z):
  
    a = 5 * z - (3 * x + y)
    
  
    if all(-10**9 <= num <= 10**9 for num in [x, x, x, y, a]):
        return [x, x, x, y, a]
    else:
        return -1


x = int(input())
y = int(input())
z = int(input())

result = find_set(x, y, z)


if result == -1:
    print(-1)
else:
    print(' '.join(map(str, result)))



