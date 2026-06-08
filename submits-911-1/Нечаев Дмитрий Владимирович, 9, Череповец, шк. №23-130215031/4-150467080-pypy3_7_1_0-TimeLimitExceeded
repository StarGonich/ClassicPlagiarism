n=int(input())
k=int(input())
minnod=int((n+k)*(n+1))
c=0
def NOD(n, p):
	for i in range(max(n, p), n*p+1):
		if i%n==0 and i%p==0:
			return int(i)

for i in range(n+1, n+k+1):
	r= NOD(n, i)
	if minnod > r:
		minnod = NOD(n, i)
		c = i
print(c)	