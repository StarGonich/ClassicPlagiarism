total = 0
for i in range(N):
    if t2[i] <= x: continue
    if t1[i] >= x + 3600: break
    total += min(t2[i], x + 3600) - max(t1[i], x)
    if total > T: break  # early exit