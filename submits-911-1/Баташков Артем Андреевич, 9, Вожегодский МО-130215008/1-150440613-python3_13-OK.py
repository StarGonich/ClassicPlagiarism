def is_beautiful_time(h, m):
    if h == m:
        return True
    
    str_h = f"{h:02d}"
    str_m = f"{m:02d}"
    if str_h == str_m[::-1]:
        return True
    
    time_str = f"{h:02d}{m:02d}"
    digits = list(map(int, time_str))
    for i in range(len(digits)-1):
        if digits[i+1] != digits[i]+1:
            break
    else:
        return True
    
    return False

h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

start_minutes = h1 * 60 + m1
end_minutes = h2 * 60 + m2

if start_minutes > end_minutes:
    end_minutes += 24*60 

beautiful_count = 0

for total_minutes in range(start_minutes, end_minutes + 1):
    hours = total_minutes // 60 % 24
    minutes = total_minutes % 60
    if is_beautiful_time(hours, minutes):
        beautiful_count += 1

print(beautiful_count)