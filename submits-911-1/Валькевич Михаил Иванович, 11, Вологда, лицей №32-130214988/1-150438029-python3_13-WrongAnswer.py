h1=input()
m1=input()
h2=input()
m2=input()
k=0
if m1=='0':
    m1='00'
if m2=='0':
    m2='00'
for i in range(int(h1+m1),int(h2+m2)):
    if i%100<=60:
        if i%100==i//100:
            k+=1
        elif str(i)[2:4][::-1]==str(i)[0:2] or str(i)[2:4]==str(i)[0:2][::-1]:
            k+=1
        else:
            if i%10-1==i%100//10 and i%100//10-1==i//100%10 and i//100%10-1==i//1000:
                k+=1
print(k)
