u = int(input())
s = 0
d = ('')
for i in range(1, u+1):
	if u % i == 0:
		s = s + i
		d = (d, str(i))
print(s)
print(d)