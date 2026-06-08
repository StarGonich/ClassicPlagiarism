N = int(input())
T = int(input())
day = list()
s = 0

for i in range(3600*24):
    day.append(0)

for i in range(N):
    t1, t2 = map(int, input().split())
    for j in range(t1, t2):
        day[j] = 1

for i in range(len(day)-3599):
    for j in range(3600):
        s += day[i+j]
    if s > T:
        print(i)
        exit()
    s = 0
print(-1)
