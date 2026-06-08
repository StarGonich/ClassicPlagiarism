def solve():
    n = int(input())
    t = int(input())
    ads = []
    for _ in range(n):
        start, end = map(int, input().split())
        ads.append((start, end))

    possible_starts = set()
    for start, end in ads:
        possible_starts.add(start - 3600 if start >= 3600 else 0) #начало часа может располагаться за 3600 секунд до начала рекламы или начинаться с 0.
        possible_starts.add(start)
        possible_starts.add(end - 3600 if end >= 3600 else 0)
        possible_starts.add(end)

    possible_starts = sorted(list(possible_starts))

    for start_time in possible_starts:
        total_ad_time = 0
        for ad_start, ad_end in ads:
            intersection_start = max(start_time, ad_start)
            intersection_end = min(start_time + 3600, ad_end)

            if intersection_start < intersection_end:
                total_ad_time += (intersection_end - intersection_start)

        if total_ad_time > t:
            print(start_time)
            return

    print("-1")

solve()
