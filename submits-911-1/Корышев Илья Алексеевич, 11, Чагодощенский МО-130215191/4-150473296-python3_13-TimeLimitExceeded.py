from math import*

n = int(input())
k = int(input())

def dividors(n):
    div = set()
    for x in range(1, int(sqrt(n))+1):
        if n%x==0:
            div.add(x)
            div.add(n//x)
    return sorted(div)
    
def find(p):
    div = dividors(p)
    ind = 0
    while ind < len(div):
        if (n*div[ind])%p==0:
            return n*div[ind]
        else:
            ind+=1
    return 10000000
    
p_arr = [p for p in range(n+1,n+k+1)]

k = map(find, p_arr)
k = list(k)
print(p_arr[k.index(min(k))])