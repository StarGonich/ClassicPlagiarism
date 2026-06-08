def nok(x, y):
    global ans
    if x != y:
        if x+y < 1000:
            for i in range(1, 100000):
                if i//x == i/x and i//y == i/y:
                    ans = i
                    break
        elif x+y > 1000 and x+y < 1000000:
            for i in range(100000, 10000000000):
                if i//x == i/x and i//y == i/y:
                    ans = i
                    break
        else:
            for i in range(10000000000, 1000000000000000):
                if i//x == i/x and i//y == i/y:
                    ans = i
                    break
    else:
        ans = x

n = int(input())
k = int(input())
a = ''
b = ''
c = 0
d = 0
e = 0
min1 = 10000000
for p in range(n+1, n+k+1):
    nok(n, p)
    a = a+str(ans)+' '
    b = b+str(p)+' '
    c = c+1
a = a.split()
b = b.split()
for i in range(0, c):
    if int(a[i]) < min1:
        min1 = int(a[i])
        d = i
        e = b[i]
print(e)