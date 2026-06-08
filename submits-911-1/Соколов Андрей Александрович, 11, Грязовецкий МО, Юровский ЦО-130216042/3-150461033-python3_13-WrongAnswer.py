import sys
from bisect import bisect_left

input = sys.stdin.readline
N = int(input())
T = int(input().strip())

a = [tuple(map(int, input().split())) for _ in range(N)]
starts = [x for x,y in a]
ends = [y for x,y in a]
pref = [0]*(N+1)
for i in range(N):
    pref[i+1] = pref[i] + (ends[i]-starts[i])

cands = {0}
for x,y in a:
    cands.add(x)
    cands.add(max(0, y-3600))

cands = sorted(cands)

def cover(X):
    L = bisect_left(starts, X)
    R = bisect_left(starts, X+3600)
    s = pref[R] - pref[L]                    # суммы полных интервалов с start in [L, R-1]
    # возможно частичный интервал слева (индекс L-1)
    if L > 0 and ends[L-1] > X:
        s += min(ends[L-1], X+3600) - X
    # возможно последний из [L, R-1] выходит за правую границу -> мы пересчитали его целиком, нужно откорректировать
    if R-1 >= L and ends[R-1] > X+3600:
        s -= ends[R-1] - (X+3600)
    return s

ans = -1
for X in cands:
    if cover(X) > T:
        ans = X
        break

print(ans)