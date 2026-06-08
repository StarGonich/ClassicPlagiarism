h1= int(input("Первые часы"))
h2= int(input("Вторые часы"))
for i in range(2):
count=0
if h1<0:
    False
else:
    print(h1)
    True
if h2>23:
    False
else:
    print(h2)
    True
m1= int(input("Первые минуты"))
m2= int(input("Вторые минуты"))
if m1<0:
    False
else:
    True
if m2>59:
    False
else:
    True
def raven(h1,h2,m1,m2):
    if h1==h2:
        h1=h2
    else:
        False
    if m1==m2:
    else:
        False
def sovpad(h1,m1,h2,m2):
    if h1==h2 and m1==m2:
        if h1==m1:
            count+=1
        else:
            False
        if (h1%1+h1//1)==m1 or (m1%2+m1//1)==h1:
            count+=1
        else:
            False
    return h1,m1
def notsovpad(h1,m1,h2,m2):
    if h1!=h2 and m1!=m2:
        if h1==h2:
            count += 1
        else:
            False
        if (h1 % 1 + h1 // 1) == m1 or (m1 % 2 + m1 // 1) == h1:
            count += 1
        else:
            False
print(count)