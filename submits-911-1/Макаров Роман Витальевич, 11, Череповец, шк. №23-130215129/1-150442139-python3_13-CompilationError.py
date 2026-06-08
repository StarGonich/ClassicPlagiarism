h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
p=0
for i in range(h1, h2):
	for o in range(m1, m2):
		if i == o or (((i % 10)* 10)+(i // 10)) == o or i == (((o // 10)-2)*10 + ((o % 10)-2)):
        	p += 1
print(p)