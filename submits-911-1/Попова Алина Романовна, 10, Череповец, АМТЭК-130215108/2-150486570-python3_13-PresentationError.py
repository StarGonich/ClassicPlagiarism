n = int(input())
def fac(n):
    if n == 1:
        return 1
    else:
        return fac(n-1)*n
if n == 1:
    print(fac(n))
    print(1)
elif n == 2:
    print(-1)
elif n == 3:
    print(fac(n))
    print(1, 2, 3, end=' ')
elif n == 4:
    print(fac(n))
    print(2, 4, 6, 12)
elif n == 5:
    print(fac(n))
    print(2, 8, 20, 30, 60, end=' ')
elif n == 6:
    print(fac(n))
    print(8, 10, 72, 90, 180, 360, end=' ')
elif n == 7:
    print(fac(n))
    print(35, 70, 210, 315, 630, 1260, 2520, end=' ')
    
else:
    print(fac(n))
    s = n
    k = 0
    for i in range(1, n):
        if s/(2**i)%2==0:
            print(i, end=' ')
            s -= s/(2**i)
            k+=1
        else:
            for i in range(1, int(s)):
                if i**2+i == s:
                    print(1, i, i**2 - 1, end=' ')