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

ca = [i for i in ca if L >= 0]
ca.sort()

for i in ca:
    total = 0
    for t1, t2 in ads:
        start = max(t1, i)
        end = min(t2, i + 3600)
        if start < end:
            total += end - start
    if total > T:
        print(i)
        exit()

print(-1)
