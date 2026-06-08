h1 = str(input())
m1 = str(input())
h2 = str(input())
m2 = str(input())

if int(h1) < 10:
    h1 = str("0" + h1)
if int(m1) < 10:
    m1 = str("0" + m1)
if int(h2) < 10:
    h2 = str("0" + h2)
if int(m2) < 10:
    m2 = str("0" + m2)

c = 0

t1 = h1 + m1
t2 = h2 + m2

a = t1

for i in range(int(t2) - int(t1) + 1):
    if a[0] + a[1] == a[2] + a[3] or a[0] + a[1] == a[3] + a[2] or a == '0123' or a == '1234' or a == '2345':
        c += 1
    a = str(int(a) + 1)
    if len(a) < 4:
        a = ((4 - len(a)) * '0') + a

print(c)