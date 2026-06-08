n = int(input())
if n == 1:
    print(1)
elif n == 2:
    print(-1)
else:
    print(2**(n-2) * 3)
    a = 2
    for i in range(n-3):
        print((2**(n-2) * 3)//a, end = ' ')
        a *= 2
    print(3,2,1)