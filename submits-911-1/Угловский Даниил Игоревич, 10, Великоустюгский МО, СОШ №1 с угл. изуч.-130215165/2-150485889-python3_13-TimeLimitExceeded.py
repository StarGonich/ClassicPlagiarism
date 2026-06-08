n=int(input())
s=0
k=0
ans=[]
for i in range(2,1000000001,1):
	b=i
	while i!=1:
		for p in range(i-1,1,-1):
			if i%p==0:
				ans.append(p)
				i=i//p
				s=s+p
				k=k+1
		if ((k==n) and ((i==1) and (s==b))):
			print(i)
			print(ans)
		else:
			s=0
			k=0
			ans=[]
			