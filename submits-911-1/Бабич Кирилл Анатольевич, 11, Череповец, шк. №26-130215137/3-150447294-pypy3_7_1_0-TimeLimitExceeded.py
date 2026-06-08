n = int(input())
T = int(input())
intervals = []
for i in range(n):
    t1, t2 = map(int, input().split())
    intervals.append(t1)
    intervals.append(t2)
timeLine = [0] * max(intervals)
for i in range(0,2*n,2):
    for j in range(intervals[i],intervals[i+1]):
        timeLine[j] = 1
flag = True
for i in range(3600,max(intervals)):
    if sum(timeLine[i-3600:i]) > T:
        flag = False
        print(i-3600)
        break
if flag:
    print(-1)