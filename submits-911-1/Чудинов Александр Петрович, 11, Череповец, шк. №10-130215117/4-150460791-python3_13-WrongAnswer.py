n = int(input())
k = int(input())
if n % 2 == 0 and n + 2 < n+k:
	print(n+k -2)
elif n % 3 == 0 and n + 3 < n+k:
	print(n+k -3)
elif n % 5 == 0 and n + 5 < n+k:
	print(n+k -5)
elif n % 7 == 0 and n + 7 < n+k:
	print(n+k -7)
elif n % 11 == 0 and n + 11 < n+k:
	print(n+k -11)
elif n % 13 == 0 and n + 13 < n+k:
	print(n+k -13)



