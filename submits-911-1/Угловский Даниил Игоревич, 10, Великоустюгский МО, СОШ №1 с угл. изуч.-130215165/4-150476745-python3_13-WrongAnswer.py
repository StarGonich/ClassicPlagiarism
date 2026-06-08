n=int(input())
k=int(input())
c=1
a=1
b=10000000000000000
for p in range(n+1,n+k+1,1):
	while ((a%n==0) and (a%p==0)):
		a=a+1
	if a<b:
		b=a
		c=p
	else:
		a=1
print(c)
		
		