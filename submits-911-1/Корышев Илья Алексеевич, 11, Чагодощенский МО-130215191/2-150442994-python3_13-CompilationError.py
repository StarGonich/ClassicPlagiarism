from math import*

n=int(input())

def dividors(n):
    div = set()
    for x in range(1, int(sqrt(n))+1):
        if n%x==0:
            div.add(x)
            div.add(n//x)
    return sorted(div)[:-1]

if n == 1:
	print(1)
else:
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
	                text=""
	                for h in arr[start:end+1]:
	                    text+= h+" "
	                print(text)
	                break
	        if _sum > m:
	            _sum=0
	            break
	        else:
	            end+=1
		if _sum == m:
			if end+1 == n:
				break