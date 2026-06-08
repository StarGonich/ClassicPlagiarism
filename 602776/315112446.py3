n = int(input())  

if n < 12:
    a = [int(x) for x in range(4,n+1, 4) if x%4==0 and x%12!=0]
    b = [int(x) for x in range(5,n+1, 5) if x%5==0]
    c = [int(x) for x in range(6, n+1, 6) if x%6==0 and x%12!=0]
    d = a+c
    d.sort()
    print(len(d)+len(b))
else:
    print(n//4 + n//5)
