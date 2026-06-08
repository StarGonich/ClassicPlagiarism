a = int(input())
c = []
c1 = ''
d = 1
b = 0
while d < a or b != a:
    if a % d == 0:
        c += [d]
        c1 = c1 + str(d) + ' '
    b = sum(c)
    d += 1
if b == a:
    print(b)
    print(c1[0:len(c1)-1])
else:
    print(-1)