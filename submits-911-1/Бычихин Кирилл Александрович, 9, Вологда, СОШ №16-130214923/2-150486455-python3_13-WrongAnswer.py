n = int(input())
if n == 1:
    m = 1
    divs = [1]
    print(m)
    print(' '.join(map(str, divs)))
elif n == 2:
    print(-1)
if n >= 3:
    m = n*(n+1)//2
    divs = list(range(1, n+1))
    print(m)
    print(' '.join(map(str, divs)))
else:
    print(-1)