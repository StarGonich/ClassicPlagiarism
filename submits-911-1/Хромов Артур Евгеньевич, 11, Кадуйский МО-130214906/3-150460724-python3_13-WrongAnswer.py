n = int(input())
t_limit = int(input())

ads = []
for x in range(n):
    t1, t2 = map(int, input().split())
    ads.append((t1, t2))

if not ads:
    print("-1")

potential_starts = set()

max_ad_end = 0
if ads:
    max_ad_end = max(ad[1] for ad in ads)

for t1, t2 in ads:
    start_hour_candidate_t1 = (t1 // 3600) * 3600
    for h_offset in [-3600, 0, 3600]:
        potential_start = start_hour_candidate_t1 + h_offset
        if potential_start >= 0 and potential_start <= max_ad_end + 3600:
            potential_starts.add(potential_start)

    start_hour_candidate_t2 = ((t2 - 1) // 3600) * 3600
    for h_offset in [-3600, 0, 3600]:
        potential_start = start_hour_candidate_t2 + h_offset
        if potential_start >= 0 and potential_start <= max_ad_end + 3600:
            potential_starts.add(potential_start)

for t1, t2 in ads:
    if t1 >= 0 and t1 <= max_ad_end + 3600:
        potential_starts.add(t1)
    if t2 >= 0 and t2 <= max_ad_end + 3600:
        potential_starts.add(t2)

sorted_potential_starts = sorted(list(potential_starts))

for start_hour_interval in sorted_potential_starts:
    end_hour_interval = start_hour_interval + 3600
    current_ad_time = 0
    
    for t1, t2 in ads:
        overlap_start = max(t1, start_hour_interval)
        overlap_end = min(t2, end_hour_interval)
        
        if overlap_start < overlap_end:
            current_ad_time += (overlap_end - overlap_start)
    
    if current_ad_time > t_limit:
        print(start_hour_interval)

print("-1")
