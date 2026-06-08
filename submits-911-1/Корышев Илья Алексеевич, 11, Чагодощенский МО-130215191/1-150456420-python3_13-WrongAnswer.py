h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

count = 0

tm1 = h1*60+m1
tm2 = h2*60+m2

def f(n):
    return f"0{n}" if n < 10 else str(n)

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

def detime(t):
    h = t//60
    m = t%60
    return (f(h), f(m))

for tm in range(tm1,tm2+1):
    t = detime(tm)
    if check(t[0], t[1]):
        count += 1

if h2<h1 or (h1==h2 and m2<m1):
    print(0)
else:
    print(count)