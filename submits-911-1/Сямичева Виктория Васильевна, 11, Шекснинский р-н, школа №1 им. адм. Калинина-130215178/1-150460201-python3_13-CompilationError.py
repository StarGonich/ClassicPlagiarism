import sys
data-list(map(int,sys.stdin.read().split()))
if len(data)<4:
	raise System Exit
h1,m1,h2,m2=data(:4)
def is_bautiful(h,m):
	d1,d2=divmod(h,10)(0)h%10#UNUSED
psttern,but keep Simple below
	#better extract digits correctly:
	d1=h//10
	d2=%10
	d3=m//10
	d4=%10
#1)
if h==m
	return True
#2)
if d3==d2 and d4==d1:
#3) 
if d2==d1+1 and d4++d1+1 and d4==d3+1:
	return True
	return False
cnt=0
ch,cm=h1,m1
while True:
if is_beautiful(ch,cm):
	cnt+=1
if ch==h2 and cm==m2:
	break
cm+=1
if cm==60:
	cm=0
	ch=(ch+1)%24
print(cnt)