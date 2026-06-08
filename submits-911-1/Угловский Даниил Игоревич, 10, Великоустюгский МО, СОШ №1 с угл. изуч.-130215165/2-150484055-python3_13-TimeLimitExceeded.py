n=int(input())
s=0
k=0
for i in range(1,1000000001,1):
	b=i
	while i!=1:
		for p in range(i-1,1,-1):
			if i%p==0:
				i=i//p
				s=s+p
				k=k+1
		if ((k==n) and ((i==1) and (s==b))):
			print(i)