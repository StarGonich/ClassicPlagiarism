def is_beautiful(h, m):
    hh = f"{h:02d}"
    mm = f"{m:02d}"
    digits_h = list(hh)
    digits_m = list(mm)
    
    if hh == mm:
        return True
    

    if digits_m == digits_h[::-1]:
        return True
    
    combined = digits_h + digits_m
    for i in range(3):
        if int(combined[i]) + 1 != int(combined[i+1]):
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
    start_minutes = h1 * 60 + m1
    end_minutes = h2 * 60 + m2
    current_minutes = current_h * 60 + current_m
    
    if start_minutes > end_minutes:
        in_range = current_minutes >= start_minutes or current_minutes <= end_minutes
    else:
        in_range = start_minutes <= current_minutes <= end_minutes
    
    if in_range:
        if is_beautiful(current_h, current_m):
            count += 1
    
    current_m += 1
    if current_m == 60:
        current_m = 0
        current_h += 1
    if current_h == 24:
        current_h = 0
    
    if start_minutes <= end_minutes:
        if current_minutes > end_minutes:
            break
    else:
        if current_minutes == end_minutes:
            break