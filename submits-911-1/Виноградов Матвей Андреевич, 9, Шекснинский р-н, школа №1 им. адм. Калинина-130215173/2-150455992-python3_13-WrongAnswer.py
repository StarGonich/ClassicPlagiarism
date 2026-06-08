n = int(input())

if n == 1:
    print(1)
    print(1)
elif n == 2:
    print(-1)
elif n == 3:
    print(6)
    print("1 2 3")
elif n == 4:
    print(12)
    print("1 2 3 6")
elif n == 5:
    print(24)
    print("1 2 3 4 14")  
else:

    if n % 2 == 0:
        m = (2 ** (n - 1)) * 3
    else:
       
        m = (2 ** (n - 2)) * 3 
    print(m)
    
    e = []
    for i in range(n - 1):
        e.append(2 ** i)
    
   
    if n % 2 == 0:
        e.append(3 * (2 ** (n - 2)))
    else:
        e.append(3 * (2 ** (n - 3))) 

    print(" ".join(map(str, e)))