n = int(input())
t = int(input())
t1l = [0] * (n + 1)
t2l = [0] * (n + 1)
ts = 0
k = 0
tp = 0
tn = 0
ts = 0
for i in range(n):
    t1, t2 = map(int, input().split())
    t1l[i] = t1
    t2l[i] = t2
for i in range(n):
    if t2l[i] + 3600 > t1l[i + 1]:
        ts = ts + t2l[i] - t1l[i]
        k = k + 1
        if ts > t:
            tn = t2l[i] - tp - 3600 + 1
            if tn > t1l[i - k + 1]:
                tn = t1l[i - k + 1] + 1
            if tn <= 0:
                tn = 1
            break
        tp = tp + t2l[i] - t1l[i]
    else:
        if k != 0:
            ts = 0
            tn = 0
        
print(tn)