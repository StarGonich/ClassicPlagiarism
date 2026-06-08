import sys
import bisect

def readints():
    return list(map(int, sys.stdin.readline().split()))

def make_f(ads):
    n = len(ads)
    t1s = [a for a,b in ads]
    t2s = [b for a,b in ads]
    lens = [t2s[i] - t1s[i] for i in range(n)]
    pref = [0] * (n + 1)
    for i in range(n):
        pref[i+1] = pref[i] + lens[i]

    def f(S):
        E = S + 3600
        L = bisect.bisect_right(t2s, S)
        idx_right = bisect.bisect_left(t1s, E)
        R = idx_right - 1
        if L > R:
            return 0
        if L == R:
            return max(0, min(t2s[L], E) - max(t1s[L], S))
        ol = max(0, min(t2s[L], E) - max(t1s[L], S))
        orr = max(0, min(t2s[R], E) - max(t1s[R], S))
        mid = pref[R] - pref[L+1] if R - 1 >= L + 1 else 0
        return ol + mid + orr

    return f

def main():
    it = sys.stdin
    n_line = it.readline().strip()
    if not n_line:
        return
    N = int(n_line)
    T = int(it.readline().strip())
    ads = []
    for _ in range(N):
        a,b = map(int, it.readline().split())
        ads.append((a,b))
    if N == 0:
        print(-1)
        return

    ads.sort()
    f = make_f(ads)

    t1s = [a for a,b in ads]
    t2s = [b for a,b in ads]
    max_t2 = max(t2s)
    events = set([0, max_t2 + 1])
    for a,b in ads:
        for x in (a-3600, a-3600+1, a, a+1, b-3600, b-3600+1, b, b+1):
            if x >= 0 and x <= max_t2 + 1:
                events.add(x)
    events = sorted(events)
    for i in range(len(events) - 1):
        start = events[i]
        end = events[i+1]
        if start > end - 1:
            continue
        val_start = f(start)
        if val_start > T:
            print(start)
            return
        val_end = f(end - 1)
        if val_end <= T:
            continue
        lo, hi = start, end - 1
        while lo < hi:
            mid = (lo + hi) // 2
            if f(mid) > T:
                hi = mid
            else:
                lo = mid + 1
        print(lo)
        return

    print(-1)

if __name__ == "__main__":
    main()