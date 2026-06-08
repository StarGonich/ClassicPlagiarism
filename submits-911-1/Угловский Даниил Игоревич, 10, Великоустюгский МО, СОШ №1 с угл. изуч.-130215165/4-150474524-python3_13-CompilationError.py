n=int(input())
k=int(input())
c=1
a=1
b=100000000000000
ans[]
if n<=k:
	p=2*n
	print(p)
else:
	for i in range(n+1,n+k+1,1):
		while ((a%n==0) and (a%p==0)):
			a=a+1
		if a<b:
			b==a
			c==i
		a=1
	print(c)
		
		