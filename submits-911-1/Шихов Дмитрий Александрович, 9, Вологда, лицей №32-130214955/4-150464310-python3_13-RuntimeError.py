def nok(x, y):
    global ans
    if x != y:
        for i in range(1, 1000):
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
#p >= n+1 and p <= n+k
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