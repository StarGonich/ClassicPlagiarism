n = int(input())
T = int(input())

ads = []
for _ in range(n):
    t1, t2 = map(int, input().split())
    ads.append((t1, t2))

candidates = [0]
for t1, t2 in ads:
    candidates.append(t2)

ans = -1

for S in candidates:
    total = 0
    end_hour = S + 3600
    for t1, t2 in ads:
        if t2 <= S:
            continue
        if t1 >= end_hour:
            break  
        overlap_start = max(t1, S)
        overlap_end = min(t2, end_hour)
        total += overlap_end - overlap_start
        if total > T:
            break
    if total > T:
        ans = S
        break  
print(ans)
