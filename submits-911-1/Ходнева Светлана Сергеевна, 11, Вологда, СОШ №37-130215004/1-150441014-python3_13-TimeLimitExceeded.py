h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
k=0
s=[123,1234,2345,3456,4567,5678,6789]
while h1!=h2 or m1!=m2:
	a=m1//10+(m1%10)*10
	b=h1*100+m1
	if (h1==m1) or (h1==a) or (b in s): k+=1
	m1+=1
	if m1>=60: 
		h1+=1
		m1=0
	if h2==h1 and m2==m1:
		break
print(k)