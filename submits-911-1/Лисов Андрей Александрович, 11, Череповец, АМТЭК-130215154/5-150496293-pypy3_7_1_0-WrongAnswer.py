k = int(input())
n = int(input())
m = int(input())
sum1 = 0
sum2 = 0


for s in range(n):
	sum1 += sum(map(int, input().split()))

for s in range(n):
	sum2 += sum(map(int, input().split()))

if sum2 > sum1:
	print("2 1")
else:
	print("1 2")
