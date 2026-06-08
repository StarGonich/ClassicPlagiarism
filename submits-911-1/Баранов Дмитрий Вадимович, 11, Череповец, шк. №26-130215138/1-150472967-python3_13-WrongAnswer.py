h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0

for h in range(h1,h2 + 1):
    for m in range(m1, m2 + 1):
        if h > 9:
            a = str(h)[-1] + str(h)[-2]
        else:
            a = str(h)
        if m > 9:
            b = str(m)[-1] + str(m)[-2] 
        else:
            b = str(m)
            if h == int(b) or m == int(a):
                k += 1                
        if m > 9:
            n1 = str(h)[0]
            n2 = str(h)[1]
            n3 = str(m)[0]
            n4 = str(m)[1]
            if int(n1) + 1 == int(n2) and int(n2) + 1 == int(n3) and int(n3) + 1 == int(n4):
                k += 1            
        
        if h == m:
            k += 1
        
print(k)