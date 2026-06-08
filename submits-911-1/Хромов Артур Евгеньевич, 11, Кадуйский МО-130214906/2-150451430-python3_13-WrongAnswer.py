def s(x):
    for i in range(2, (x//2)+1):
        if x % i == 0:
            return False
    return True

n = int(input())

a = []

if n <= 0:
    print(-1)
else:
    for x in range(1, 10**9):
        if s(x):
            a = [x] + a
        if len(a) == n:
            print(sum(a))
            for c in a:
                print(c, end=' ')
            break