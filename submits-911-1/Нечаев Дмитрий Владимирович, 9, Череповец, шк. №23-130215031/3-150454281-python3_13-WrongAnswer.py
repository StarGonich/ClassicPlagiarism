n=int(input())
t=int(input())
list=[]
for i in range(n):
	t1, t2 = map(int, input().split())
	 
	print(t1, t2)
	if t2-t1>t:
		if t2-(t2%3600)==t1-(t1%3600):
			r=str(t2-(t2%3600)+1)
			list.append(r)
		elif t2-(t2%3600)!=t1-(t1%3600) and 3600-t1>t:
			r=str(t1-(t1%3600)+1)
			list.append(r)
		elif t2-(t2%3600)!=t1-(t1%3600) and t2>t:
			r=str(t2%3600)
			list.append(r)
print(list)
if len(list)!=0:
	print(min(list))
else:
	print(-1)