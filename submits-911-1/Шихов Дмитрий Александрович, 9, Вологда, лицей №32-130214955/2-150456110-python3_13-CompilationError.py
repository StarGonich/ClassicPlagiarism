from random import *

a = int(input())
b = ''
c = 0
d = 0
e = ''

for i in range(1, 1000):
	b = ''
    c = 0
	for x in range(1, i):
		if i%x == 0:
			b = b+str(x)+' '
			c = c+1
	b = b.split()
	for y in range(0, 1000):
		for z in range(0, a):
			e = e+b[randint(0, c-1)]+' '
		for f in range(0, len(e)):
			if f%2 == 0:
				d = d+int(e[f])
		if d == i:
			print(i)
			print(e)
			break
		
			
