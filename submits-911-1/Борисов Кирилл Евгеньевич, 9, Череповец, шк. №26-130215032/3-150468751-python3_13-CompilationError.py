N=int(input())
T=int(input())
y=0
x=0
while y!=N:
	t1, t2=map(int,input().split())
	y+=1
	x+=t2-t1
	if T<=x:
		