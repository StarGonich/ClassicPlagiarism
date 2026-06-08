a = int(input())
b = int(input())
c = int(input())
d = int(input())
ans = 0

r = (c-a)*60+(d-b)
for i in range(0, r):
	if b == 60:
		a = a+1
		b = 0
	if a == b:
		ans = ans+1
	elif a[0] == b[1] and a[1] == b[0]:
		ans = ans+1
	elif a[1] == a[0]+1 and b[0] == a[1]+1 and b[1] == b[0]+1:
		ans = ans+1
print(ans)