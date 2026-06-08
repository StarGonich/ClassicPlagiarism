n = int(input())
t = int(input())
y = ''
c = 0
d = 0
e = 0
f = 0
for i in range(0, n):
    t1, t2 = map(int, input().split())
    y = y+str(t1)+' '+str(t2)+' '
y = y.split()
for x in range(0, 1000000):
    d = 0
    c = x+3600
    for z in y:
        if int(z) > c:
            break
        elif e%2 != 0:
            d = d+int(y[e])-int(y[e-1])
        if d > t:
            print(x)
            f = 1
            break
    if f == 1:
        break
if f != 1:
    print('-1')