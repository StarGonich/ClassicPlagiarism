m1 = int(input())
m2 = int(input())
k1 = int(input())
k2 = int(input())
mn1 = m1*60+m2
if k1 < m1 or k2 < m2: mn2 = 1440 + k1*60+k2
else: mn2 = k1*60+k2
#print(mn1, mn2)
a1 = m1
a2 = m2
c = 0
for i in range(mn2 - mn1 + 1):
    if a2 == 60:
        a2 = 0
        a1 +=1
    if a1 == 24:
        a1 = 0
    if a1 == a2 or str(a1) == str(a2%10) + str(a2//10) or str(a2) == str(a1%10) + str(a1//10): c+=1
    if a1//2 - a1%10 == -1 and a1%10 - a2//2 and a2//2 - a2%10 == -1: c+=1
    a2 += 1
print(c)