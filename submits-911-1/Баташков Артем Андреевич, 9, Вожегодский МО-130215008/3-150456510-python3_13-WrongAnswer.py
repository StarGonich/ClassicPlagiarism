def check_advertising_violation(N, T, ads):
    starts = []
    ends = []
    
    for start, end in ads:
        starts.append(start)
        ends.append(end)
        
    max_time = max(starts[-1], ends[-1]) if len(starts) > 0 else 0
    
    for hour_start in range(max_time // 3600 * 3600, -1, -3600):
        ad_duration_in_hour = 0
        
        for i in range(len(starts)):
            if starts[i] <= hour_start + 3600:
                overlap_start = max(hour_start, starts[i])
                overlap_end = min(hour_start + 3600, ends[i])
                
                ad_duration_in_hour += overlap_end - overlap_start
            
        if ad_duration_in_hour > T:
            return hour_start
    
    return -1


import sys
input = sys.stdin.read
data = input().split()

N = int(data[0])
T = int(data[1])
ads = [(int(data[2*i+2]), int(data[2*i+3])) for i in range(N)]

result = check_advertising_violation(N, T, ads)
print(result)