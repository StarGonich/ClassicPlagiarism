u = int(input())
s = 0
for i in range(2, u+1):
	if u % i == 0:
		s = s + i
		d = ('1', str(i))
print(s)
print(d)