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
x=0
if n*2<n+k:
	x=n*2
else: x=n+k
for p in range(n+1,x+1):
	if n*p/nod(p,n)<mn:
		mn=n*p/nod(p,n)
for p in range(n+1,x+1):
	if mn==n*p/nod(p,n):
		print(p)
	
	