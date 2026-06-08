from bisect import bisect_left as bl
one = 0

n = int(input())
T = int(input())

pref = [0]*(n+1)
end = [0]*n
start = [0]*n

t1, t2 = map(int, input().split())
pref[0] = t2-t1 +one#
start[0] = t1
end[0] = t2
for i in range(1, n):
    t1, t2 = map(int, input().split())
    pref[i] = pref[i-1]+t2-t1 +one#
    start[i] = t1
    end[i] = t2

#rint(pref, start, end)

for i in range(n):
    x = end[i]-3600+one #
    endX = bl(end, x)
    startX = bl(start, x)
    if endX == startX:
        time = pref[i]-pref[startX-1]
    else:
        time = pref[i]-pref[endX] + end[startX-1]-x+one#

    #print(x, endX, startX, time)

    if time>=T:
        if x+1<0:
            print(0)
        else:
            print(x-(time-T)+1)
        break
else:
    print(-1)
