def time(a,b):
	if a==b or (a%10==b//10 and a//10==b%10) or (a//10+2==b//10 and a%10+2==b%10 and a//10+1==a%10):
		return True
k=0
h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
if h1>h2:
	for i in range (h1,25+h2):
		for j in range (0,60):
			if time(i%24,j)==True and ((i!=h1 and i!=h2+24) or (i==h1 and j>=m2) or (i==h2+24 and j<=m2)):
				k+=1
if h1<h2:
	for i in range (h1, h2+1):
		for j in range(0,60):
			if time(i%24,j)==True and ((i!=h1 and i%24!=h2) or (i==h1 and j>=m2) or (i%24==h2 and j<=m2)):
				k+=1
if h1==h2 and m1>m2:
	for i in range (h1, h2+25):
		for j in range(0,60):
			if time(i%24,j)==True and ((i!=h1 and i!=h2+24) or (i==h1 and j>=m2) or (i==h2+24 and j<=m2)):
				k+=1
if h1==h2 and m1<m2:
	for i in range (h1, h2+1):
		for j in range(0,60):
			if time(i%24,j)==True and ((i!=h1 and i%24!=h2) or (i==h1 and m1<=j<=m2)):
				k+=1
if h1==h2 and m1==m2:
	if time(h2,m2)==True:
		k+=1
if (h1==0 and m1==0) or (h1>h2) or (h1==h2 and m1>m2) or (h2==0 and m2==0):
	k+=1
print(k)