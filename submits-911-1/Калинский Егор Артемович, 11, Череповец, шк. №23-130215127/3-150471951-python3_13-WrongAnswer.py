N = int(input())
T = int(input())
ad = dict()
k = 0
for _ in range(N):
    t1, t2 = map(int, input().split(' '))
    time = t2 - t1
    ad[t1] = time
t = 1
for i in ad.keys():
    if i < 3600 * t:
        k += ad[i]
    else:
        k = 0
        t += 1
        k += ad[i]
    if  k > T:
        g = ((i + ad[i]) - (k - T)) % 3600 + 1
        print(g)
        break
else:
    print(-1)

