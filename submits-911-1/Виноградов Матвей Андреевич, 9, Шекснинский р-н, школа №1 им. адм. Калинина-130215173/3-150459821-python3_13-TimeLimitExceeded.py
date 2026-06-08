n = int(input())
t = int(input())

ads = []
for _ in range(n):
    t1, t2 = map(int, input().split())
    ads.append((t1, t2))

found = False
start_time = 0

min_start = max(0, ads[0][0] - 3600)
max_start = ads[-1][1] 

for hour_start in range(min_start, max_start + 1):
    total_ad_time = 0
    
 
    for ad_start, ad_end in ads:
       
        if ad_start < hour_start + 3600 and ad_end > hour_start:

            overlap_start = max(ad_start, hour_start)
            overlap_end = min(ad_end, hour_start + 3600)
            total_ad_time += overlap_end - overlap_start
    
    if total_ad_time > t:
        print(hour_start)
        found = True
        break

if not found:
    print(-1)
