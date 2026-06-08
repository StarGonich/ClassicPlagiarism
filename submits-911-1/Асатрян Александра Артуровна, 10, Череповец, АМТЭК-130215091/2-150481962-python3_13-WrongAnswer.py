n = int(input())
x = 0
if n == 1:
    print(1)
    print(1)
else:
    a = [1] * n
    s = 1
    for i in range(n):
        a[i] += i    
    while x < 10000:
        k = sum(a)
        q = True
        for i in a:
            if k % i != 0:
                q = False
                break
        if q is True:
            print(k)
            print(*a)
            x = 122344
            break
        else:
            x += 1
            a[-s] += 1
            if s < n:
                s += 1
            else:
                s = 1
    if q is False:
        print(-1)