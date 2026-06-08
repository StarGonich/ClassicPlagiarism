N = int(input())
T = int(input())
count = 0
for i in range(N):
    t1, t2 = map(int, input().split())
    if t2 - t1 >= T:
        count += (t2 - 3899)
        break
if count > 0:
    print(count)
else:
    print("-1")
    