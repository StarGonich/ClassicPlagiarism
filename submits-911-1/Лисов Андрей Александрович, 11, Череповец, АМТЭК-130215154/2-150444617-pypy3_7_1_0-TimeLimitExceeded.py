def getDels(num):
	dels = []
	for d in range(1, int(num ** 0.5) + 1):
		if num % d == 0:
			dels.append(d)
			if d != num // d :
				dels.append(num // d)
	return dels

def bam(num, n):
	dels = sorted(getDels(num), reverse = True)
	#print(dels)
	lena = len(dels)
	index = 0
	qq = []
	q = 0
	while n:
		if index >= lena:
			return False
		#print(q)
		#print(q + dels[index], n)
		if (q + dels[index] < num) or (q + dels[index] == num and n == 1):
			q += dels[index]
			qq.append(dels[index])
			#print(dels[index])
			index += 1
			n -= 1
			#print(n)

		else:
			index += 1
	if q == num:
		return qq
	return False

n = int(input())
for i in range(1000000000):
	result = bam(i, n)
	if result:
		print(i)
		print(*result)
		break

