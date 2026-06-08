h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
p=0
if h1 == h2:
	for i in range(h1, h2):
		for o in range(m1, m2):
			if i == o or (((i % 10)* 10)+(i // 10)) == o or i == (((o // 10)-2)*10 + ((o % 10)-2)):
        		p = p + 1
if h1 < h2:
	for o in range(m1, 59):
		if h1 == o or (((h1 % 10)* 10)+(h1 // 10)) == o or h1 == (((o // 10)-2)*10 + ((o % 10)-2)):
        	p = p + 1
	for i in range(h1+1, h2-1):
		for o in range(1, 59):
			if i == o or (((i % 10)* 10)+(i // 10)) == o or i == (((o // 10)-2)*10 + ((o % 10)-2)):
        		p = p + 1
	for o in range(1, m2):
		if h2 == o or (((h2 % 10)* 10)+(h2 // 10)) == o or h2 == (((o // 10)-2)*10 + ((o % 10)-2)):
        	p = p + 1
print(p)