n = int(input())
T = int(input())

ads = []
for _ in range(n):
    t1, t2 = map(int, input().split())
    ads.append((t1, t2))

ca = set()
for t1, t2 in ads:
    ca.add(t1)
    ca.add(t2)
    ca.add(t1 - 3599)
    ca.add(t2 - 3599)

ca.add(0)
ca = sorted([s for s in ca if s >= 0])


for i in ca:
    total = 0
    hh = i + 3600
    for t1, t2 in ads:
        if t2 <= i or t1 >= hh:
            continue
        overlap = min(t2, hh) - max(t1, i)
        total += overlap
        if total > T:
            break
    if total > T:
        print(i)
        exit()

print(-1)
