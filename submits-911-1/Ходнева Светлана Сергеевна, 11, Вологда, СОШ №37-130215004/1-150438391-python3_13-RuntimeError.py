h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
k=0
if h1>9: sh1=str(h1)
else: sh1='0'+str(h1)
if m1>9: sm1=str(m1)
else: sm1='0'+str(m1)
while h1!=h2 or m1!=m2:
	if h1==m1: k+=1
	elif sh1==sm1[::-1]: k==1
	elif h//10+1==h1%10 and h1%10+1==m1//10 and m1//10+1==m1%10: k+=1
	if m1>=60: 
		h1+=1
		m1=0
	m1+=1
	