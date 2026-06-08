n = int(input())
if n == 1:
    print(1)
    print(1)
else:
    m = (2**n)-2 
    if m > 10**9:
        print(-1)
    else:
        print(m)
        d = [2**i for i in range(n)]
        print(*d)
