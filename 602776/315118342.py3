import bisect
n = int(input())
x = list(map(int, input().split()))
d = list(map(int, input().split()))
k = int(input())
s = [k-1]
visited = []
res = 0
while s:
    i = s.pop()
    visited.append(i)
    res += 1
    lpos = x[i] - d[i]
    rpos = x[i] + d[i]
    r = bisect.bisect_left(x, rpos)
    l = bisect.bisect_left(x, lpos)
    for w in range(l, i):
        if w not in visited:
            s.append(w)
    for w in range(i+1, r):
        if w not in visited:
            s.append(w)
print(res)

