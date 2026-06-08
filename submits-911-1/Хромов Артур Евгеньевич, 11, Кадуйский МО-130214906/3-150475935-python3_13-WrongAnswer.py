def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    idx = 0
    N = int(data[idx]); idx += 1
    T = int(data[idx]); idx += 1
    
    ads = []
    for _ in range(N):
        t1 = int(data[idx]); idx += 1
        t2 = int(data[idx]); idx += 1
        ads.append((t1, t2))
    
    candidates = set()
    candidates.add(0)
    for t1, t2 in ads:
        candidates.add(t1)
        if t2 >= 3600:
            candidates.add(t2 - 3600)
    
    candidates = sorted(candidates)
    
    ans = -1
    for left in candidates:
        if left < 0:
            continue
        right = left + 3600
        total = 0
        for t1, t2 in ads:
            if t2 <= left or t1 >= right:
                continue
            total += min(t2, right) - max(t1, left)
            if total > T:
                ans = left
                break
        if ans != -1:
            break
    
    print(ans)

if __name__ == "__main__":
    main()