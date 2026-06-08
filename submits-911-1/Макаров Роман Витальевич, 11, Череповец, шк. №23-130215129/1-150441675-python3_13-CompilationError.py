h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
p=0
for i in range(h1, h2):
	for o in range(m1, m2):
		if i == o:
        	p += 1
        elif (((i % 10)* 10)+(i // 10)) == o:
        	p += 1
        elif i == (((o // 10)-2)*10 + ((o % 10)-2)):
        	p += 1
print(p)