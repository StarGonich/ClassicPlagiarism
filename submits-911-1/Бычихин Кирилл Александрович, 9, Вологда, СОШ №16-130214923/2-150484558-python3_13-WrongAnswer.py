n = int(input())

if n == 1:
    m = 1
    divs = [1]
    print(m)
    print(' '.join(map(str, divs)))
elif n == 3:
    m = 6
    divs = [1, 2, 3]
    print(m)
    print(' '.join(map(str, divs)))

else:
    print(-1)