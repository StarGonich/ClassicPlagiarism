n = int ( input())
k = int ( input())
def nok(x,y):
    c = x*y
    while (x!=y):
        if x>y:
            x = x-y
        else:
            y = y-x
    return c//y
minn = 100000000
pmin = 0
for p in range ( n+1,n+k+1):

    if nok(p,n) < minn:
        minn = nok(p,n)
        pmin = p
        
print (pmin)