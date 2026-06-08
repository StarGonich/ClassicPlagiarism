u = int(input())
s = 1
d = ('1')
for i in range(2, u+1):
	if u % i == 0:
		s = s + i
		d = (d, i)
print(s)
print(d)