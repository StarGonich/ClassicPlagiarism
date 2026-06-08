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
    
answer = []
    
for p in range(n+1,n+k+1):
    div = dividors(p)
    ind = 0
    while ind < len(div):
        if (n*div[ind])%p==0:
            answer.append(n*div[ind])
            break
        else:
            ind+=1
            
print(n+1+answer.index(min(answer)))