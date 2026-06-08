n = int(input())
T = int(input())

ads = []
for _ in range(n):
    t1, t2 = map(int, input().split())
    ads.append((t1, t2))

cuvaki = set()
cuvaki.add(0)

for t1, t2 in ads:
    cuvaki.add(t1)
    cuvaki.add(t1 - 1)
    cuvaki.add(t1 + 1)
    cuvaki.add(t2)
    cuvaki.add(t2 - 1)
    cuvaki.add(t2 + 1)
    cuvaki.add(max(0, t1 - 3600))
    cuvaki.add(max(0, t1 - 3600 + 1))
    cuvaki.add(max(0, t2 - 3600))
    cuvaki.add(max(0, t2 - 3600 + 1))

cuvaki = [x for x in cuvaki if x >= 0]
cuvaki.sort()

	for start in cuvaki:
    end = start + 3600
    total = 0
    for t1, t2 in ads:
        if t2 <= start:
            continue
        if t1 >= end:
            break
        total += min(t2, end) - max(t1, start)
    if total > T:
        print(start)
        exit()

print(-1)