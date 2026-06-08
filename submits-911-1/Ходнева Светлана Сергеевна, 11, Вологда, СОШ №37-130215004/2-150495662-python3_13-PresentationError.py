n=int(input())
for i in range(1,1001):
	s=[]
	if i>=6:
		w=i//2+1
		for d in range(1,w):
			if i%d==0: 
				s.append(d)
			if sum(s)==i and len(s)==n:
				print(i)
				a=''
				for m in range(n):
					a=str(s[m])+' '
				print(a)
				break
	else:
		if n==1:
			print(i,i)
			break
if len(s)==0:
	print(-1)
		