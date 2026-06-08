n = int(input())
t = int(input())
times = []
for i in range(n):
    start, finish = map(int, input().split())
    times.append((start, finish))

# print(times, finish)

q = [False] * finish

for pr in times:
    q[pr[False] : pr[True]] = [True] * (pr[True] - pr[False])

# for index, item in enumerate(q):
# 	print(index, item)
currSum = sum(q[:3600])
bim = 0
flag = True
while bim + 3599 < finish:
    if currSum > t:
        print(bim)
        flag = False
        break
    else:
        currSum -= q[bim]
        currSum += q[bim + 3600]
        bim += 1
if flag:
	print(-1)


