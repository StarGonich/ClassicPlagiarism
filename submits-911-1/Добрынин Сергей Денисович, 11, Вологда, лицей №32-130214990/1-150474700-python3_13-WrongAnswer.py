h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
nc=0
q1=h1//10
q2=h1%10
q3=m1//10
q4=m1%10
s1=q1*1000+q2*100+q3*10+q4
q1=h2//10
q2=h2%10
q3=m2//10
q4=m2%10
s2=q1*1000+q2*100+q3*10+q4
for i in range(s1,s2):
    w1=i//1000
    w2=i//100%10
    w3=i//10%10
    w4=i%10
    if (w1+w4==w2+w3) or (w1*10+w2==w3*10+w4) or (w1*10+w2==w4*10+w3):
        nc+=1
print(nc)
