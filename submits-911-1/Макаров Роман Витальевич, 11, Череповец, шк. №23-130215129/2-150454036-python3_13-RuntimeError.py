u = int(input())
s = 0
d = ('')
for i in range(0, u):
	if u % i == 0:
		s = s + i
		d = (d, str(i))
print(s)
print(d)