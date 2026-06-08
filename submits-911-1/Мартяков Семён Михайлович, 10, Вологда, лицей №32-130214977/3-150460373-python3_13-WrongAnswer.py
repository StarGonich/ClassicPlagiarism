n = int(input())
t = int(input())

t11 = []
t22 = []
tlen = []
tsum = [0]
ans =[]

for i in range(n):
    t1, t2 = map(int, input().split())
    t11.append(t1)
    t22.append(t2)
    tlen.append(t2-t1)

for i in range(n):
    tsum.append(tsum[i] + tlen[i])

for i in range(n + 1):
    if i > t:
        end = t22[i-1] - (tsum[i] - t - 1)