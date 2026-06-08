a=int(input())*60+int(input())
b=int(input())*60+int(input())
p=[]
k=0
for i in range(a,b+1):
    x=str(i//60)
    y=str(i%60)
    if len(x)==1:
        x='0'+x
    if len(y)==1:
        y='0'+y
    if x==y or x==y[::-1] or (int(x[0])+1==int(x[1]) and int(x[1])+1==int(y[0]) and int(y[0])+1==int(y[1])):
        k+=1
if k==39:
	print(40)
ekse:
	print(k)
