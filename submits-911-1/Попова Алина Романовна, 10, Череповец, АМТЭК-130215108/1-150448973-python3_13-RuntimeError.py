h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
if m1<=h1 and m2>=h2:
    k+= (h2-h1+1)
else:
    k+=(h2-h1)
    
if h1 < 10:
    a = '0' + str(h1)
else:    
    a = str(h1)
if m1 < 10:
    b = '0' + str(m1)
else:
    b = str(m1) 
if h2 < 10:
    a2 = '0' + str(h2)
else:    
    a2 = str(h2)
if m2 < 10:
    b2 = '0' + str(m2)
else:
    b2 = str(m2) 
                
if int(a1)<= int(b1[::-1]) and int(a2)>= int(b2[::-1]):
    k+=(h2-h1+1)
else:
    k+=(h2-h1)
if ((h1 < 1) or (m1<=23 and h1 == 1)) and ((h2>1) or (m2>=23 and h2 == 1)):
    k+=1
if ((h1 < 12) or (m1<=34 and h1 == 12)) and ((h2>12) or (m2>=34 and h2 == 12)):
    k+=1
if ((h1 < 23) or (m1<=45 and h1 == 23)) and ((h2>23) or (m2>=45 and h2 == 23)):
    k+=1

print(k)

