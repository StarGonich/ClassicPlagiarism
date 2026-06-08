h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

r=0

h=h1
m=m1

while True:
    if h > h2 or (h == h2 and m > m2):
        break
    
    if h == m:
       r += 1
    else:
      
        if h < 10:
            cz1 = 0
            cz2 = h
        else: 
           cz1 = h // 10
           cz2 = h % 10
        
           
           zminutes = cz2 * 10 + cz1
        if m == zminutes and zminutes <= 59:
            r += 1
            
            if h < 10:
                d1 = 0
                d2 = h
            else:
                d1 = h // 10
                d2 = h % 10
        
            if m < 10:
                d3 = 0
                d4 = m
            else:
                d3 = m // 10
                d4 = m % 10
                if (d2 == d1 + 1) and (d3 == d2 + 1) and (d4 == d3 + 1):
                    r += 1                
     
    m += 1
    if m == 60:
         m=0
         h+=1
print(r)