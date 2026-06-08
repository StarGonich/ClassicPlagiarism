def nod(a,b):
	c=a
	d=b
	while d!=0:
		if c>d:
			c-=d
		else: d-=c
	return (c)
n=int(input())
k=int(input())
mn=n*(n+k)
for p in range(n+1,n*2+1):
	if n*p/nod(p,n)<mn:
		mn=n*p/nod(p,n)
for p in range(n+1,n+k+1):
	if mn==n*p/nod(p,n):
		print(p)
	
	