h1 = int(input())
m1=int(input())
h2=int(input())
m2=int(input())
count=0

def krasivvoe(h, m):
    if h==m or h==(m//10+(m%10*10)) or (h==1 and m==23) or (h==12 and m==34) or (h==23 and m==45):
        return 1
    else: 
        return 0
    
if (h1!=h2 and m1!=m2) or (h1!=h2 and m1==m2):    
    for i in range(m1, 60):
        count+=krasivvoe(h1, i)
    for a in range(h1+1, h2):
        for b in range(0, 60):
            count+=krasivvoe(a, b)
    for c in range(0, m2+1):
        count+=krasivvoe(h2, c)        
elif h1==h2 and m1!=m2:
    for i in range(m1, m2+1):
        count+=krasivvoe(h1, i)        
elif h1==h2 and m1==m2:
    count+=krasivvoe(h1, m1)

print(count)