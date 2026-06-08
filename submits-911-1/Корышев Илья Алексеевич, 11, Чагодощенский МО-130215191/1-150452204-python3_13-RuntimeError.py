h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

count = 0

def f(n):
    return f"0{n}" if n < 10 else str(n)

if h1==h2 and m1==m2:
    if check(f(h1),f(m1)):
        print(1)
    else:
        print(0)
else:
    def g(text):
        ind = 1
        while ind < len(text):
            if not(int(text[ind-1])+1==int(text[ind])):
                return False
            else:
                ind += 1
        return True
    
    def check(h,m): #string
        if h == m:
            return True
        elif h[::-1] == m:
            return True
        elif g(h+m):
            return True
        return False
    
    if h2 == 0:
        hours = 23-h1
    elif h1 == 0:
        hours = h2
    else:
        hours = h2-h1
        
    if hours == 0:
        for m in range(m1,m2+1):
            if check(str(h1),f(m)):
                count+=1
                
    print(count)