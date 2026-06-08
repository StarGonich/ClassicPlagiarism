import bisect

def solve():
    N = int(input())
    T = int(input())
    ads = []
    t1_list = []
    t2_list = []
    for _ in range(N):
        t1, t2 = map(int, input().split())
        ads.append((t1, t2))
        t1_list.append(t1)
        t2_list.append(t2)

    candidates = set()
    candidates.add(0)
    for t1, t2 in ads:
        candidates.add(max(0, t2 - 3600))

    candidates = sorted(candidates)

    for x in candidates:
        total = 0
       
        left = bisect.bisect_right(t2_list, x)
        right = bisect.bisect_left(t1_list, x + 3600)

        for i in range(left, right):
            total += min(t2_list[i], x + 3600) - max(t1_list[i], x)
            if total > T:
                print(x)
                return

    print(-1)