from math import*

m=int(input())

def dividors(n):
    div = set()
    for x in range(1, int(sqrt(n))+1):
        if n%x==0:
            div.add(x)
            div.add(n//x)
    return sorted(div)[:-1]
    
for m in range(2,10**9):
    arr = dividors(m)[::-1]
    _sum = arr[0]
    start = 0
    end = 1
    while end < len(arr):
        _sum+=arr[end]
        if _sum == m:
            if end+1 != n:
                _sum=0
                break
            else:
                print(m)
                print(arr[start:end+1])
                break
        if _sum > m:
            _sum=0
            break
        else:
            end+=1
            
    if _sum == m:
            if end+1 == n:
                break