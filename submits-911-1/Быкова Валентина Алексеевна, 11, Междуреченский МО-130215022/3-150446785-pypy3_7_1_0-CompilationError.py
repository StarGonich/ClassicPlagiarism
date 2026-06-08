def find_violation(N, T, ads):
    left = 0
    right = 0
    current_ad_time = 0
    
    for start in range(ads, ads[-1] + 3600): [1]
        while right < N and ads[right] < start + 3600:
            start_ad = max(ads[right], start)
            end_ad = min(ads[right], start + 3600) [1]
            if start_ad < end_ad:
                current_ad_time += (end_ad - start_ad)
            right += 1
            
            if current_ad_time > T:
                return start
        
        while left < right and ads[left] <= start + 3600: [1]
            start_ad = max(ads[left], start - 3600)
            end_ad = min(ads[left], start) [1]
            if start_ad < end_ad:
                current_ad_time -= (end_ad - start_ad)
            left += 1
    
    return -1

N = int(input())
T = int(input())
ads = [tuple(map(int, input().split())) for _ in range(N)]

print(find_violation(N, T, ads))
