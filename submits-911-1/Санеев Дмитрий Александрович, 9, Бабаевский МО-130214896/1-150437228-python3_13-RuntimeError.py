h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

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

def time_in_range(h, m, H, M):
    start = h * 60 + m
    end = H * 60 + M
    current = H * 60 + M
    return start <= current <= end



count = 0
current_h, current_m