k = int(input())
n = int(input())
m = int(input())
tuple1 = []
for i in range(k):
	for _ in range(n):
		listik = input().split()
		if listik == [0,0,0] and i == 0:
			well = '1 2'
		elif i == 1:
			well = '2 1'
		tuple1.append(listik)
print(well)	