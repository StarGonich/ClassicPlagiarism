n=int(input())
k=int(input())
minnok=int((n+k)*(n+1))
c=0
def NOK(n,p):
	for i in range(max(2*n,2*p),n*p+1):
		if i%n==0 and i%p==0:
			return int(i)			
for i in range(n+1,n+k+1):
	r=NOK(n, i)
	if minnok>r:
		minnok=r
		c=i
print(c)	