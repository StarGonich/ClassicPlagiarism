h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
if m1<=h1 and m2>=h2:
    k+= (h2-h1+1)
else:
    k+=(h2-h1)
if m1<= int(str(h1)[::-1]) and m2>= int(str(h2)[::-1]):
    k+=(h2-h1+1)
else:
    k+=(h2-h1)
if ((h1 < 1) or (m1<=23 and h1 == 1)) and ((h2>1) or (m2>=23 and h2 == 1)):
    k+=1
if ((h1 < 12) or (m1<=34 and h1 == 12)) and ((h2>12) or (m2>=34 and h2 == 12)):
    k+=1
if ((h1 < 23) or (m1<=45 and h1 == 12)) and ((h2>23) or (m2>=45 and h2 == 23)):
    k+=1

print(k)
