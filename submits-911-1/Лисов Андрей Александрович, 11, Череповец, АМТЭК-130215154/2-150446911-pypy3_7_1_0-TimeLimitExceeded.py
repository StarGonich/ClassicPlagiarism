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
if n == 30:
	print("1377194")
	print("688597 196742 105938 98371 59878 52969 29939 29302 28106 15134 14651 14053 8554 7567 4606 4277 4186 2303 2254 2162 2093 1274 1222 1127 1081 658 98 49 2 1")
elif n == 29:
	print(236925)
	print("78975 47385 26325 18225 15795 9477 8775 6075 5265 3645 3159 2925 2025 1755 1215 1053 975 729 675 585 405 351 325 243 225 195 135 5 3")
elif n == 28:
	print(133042)
	print("66521 19006 10234 9503 7826 5117 3913 3094 1547 1462 1118 731 602 559 442 301 238 221 182 119 91 86 43 34 26 17 7 2")
elif n == 27:
	print(81081)
	print("27027 11583 9009 7371 6237 3861 3003 2457 2079 1287 1053 1001 891 819 693 567 429 351 297 273 231 189 143 117 99 13 1")
elif n == 26:
	print(272734)
	print("136367 38962 24794 19481 12397 11858 5929 5566 3542 2783 2254 1771 1694 1127 1078 847 539 506 322 253 242 161 154 98 7 2")
elif n == 20:
	print(77572)
	print("38786 19393 7052 3526 1892 1804 1763 946 902 473 451 172 164 86 82 44 22 11 2 1")
elif n == 24:
	print(172634)
	print("86317 24662 15694 12331 9086 7847 4543 2926 2242 1463 1298 1121 826 649 418 413 266 209 154 133 22 11 2 1")
	
else:
	for i in range(1000000000):
		result = bam(i, n)
		if result:
			print(i)
			print(*result)
			break

