def is_beautiful(h, m):
    h1, h2 = h // 10, h % 10
    m1, m2 = m // 10, m % 10
    
    if h == m:
        return True
    
    if h1 == m2 and h2 == m1:
        return True
    
    digits = [h1, h2, m1, m2]
    for i in range(3):
        if (digits[i] + 1) % 10 != digits[i + 1]:
            break
    else:
        return True
    
    return False

h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

count = 0
current_h, current_m = h1, m1

while True:
    if is_beautiful(current_h, current_m):
        count += 1
    
    if current_h == h2 and current_m == m2:
        break
    
    current_m += 1
    if current_m == 60:
        current_m = 0
        current_h += 1
        if current_h == 24:
            current_h = 0

print(count)