h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
for i in range((h1 + m1), (h2 + m2)):
    x = h2 - h1
    if (m1 <= h1 or (m1 % 10) * 10 + m1 // h1 <= h1) and (m2 >= h2 or (m2 % 10) * 10 + m2 // h2 >= h2):
        y = x + 1
    elif (m1 > h1 or (m1 % 10) * 10 + m1 // h1 > h1) and (m2 < h2 or (m2 % 10) * 10 + m2 // h2 < h2):
        y = x - 1
        
    else:
        y = x
    if (h1 <= 11 and m1 <= 11) and (h2 >= 22 and m2 >= 22):
        z = y - 2
    elif (h1 > 11 or m1 > 11) and (h2 < 22 or m2 < 22):
        z = y
    elif (h1 < 11 or m1 < 11) and (h2 < 11 or m2 < 11):
        z = y
    elif (h1 > 22 or m1 > 22) and (h2 > 22 or m2 > 22):
        z = y
    elif (h1 > 11 or m1 > 11) and (h2 < 22 or m2 < 22):
        z = y         
    else:
        z = y - 1
    if (h1 <= 1 and m1 <= 23) and (h2 >= 23 and m2 >= 56):
        a = z + 3
    elif (h1 <= 1 and m1 <= 23) and (h2 < 12 and m2 < 34):
        a = z + 1
    elif (h1 > 12 and m1 > 34) and (h2 >= 23 and m2 >= 56):
        a = z + 1
    elif (h1 > 12 or m1 > 34) and (h2 < 23 or m2 < 56):
        a = z
    elif (h1 < 12 or m1 < 34) and (h2 > 1 or m2 > 23):
        a = z
    elif (h1 < 34 or m1 < 56) and (h2 > 1 or m2 > 23):
        a = z + 1
    else:
        a = z + 2
print(a)
