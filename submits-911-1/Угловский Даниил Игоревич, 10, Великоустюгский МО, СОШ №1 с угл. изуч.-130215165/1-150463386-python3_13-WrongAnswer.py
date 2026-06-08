h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
s=0
ans=[]
for i in range(h1+1,h2,1):
	for j in range(0,60,1):
		if ((i==j) or (j-i==11)):
			s=s+1
			ans.append(i,j)
print(s)