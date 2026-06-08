a = int(input())
s = int(input())
d = int(input())
f = int(input())
t = 0
g = '0123'
h = '2345'
if s < 10:
    k = ('0' + str(s))
else:
    k = str(s)
g=(60 * d + f) - (60 * a + s)
for i in range(g):
    if a == s:
        t += 1
    if str(a) == (k[1] + k[0]):
        t += 1
    if str(a) + str(s) == g or str(a) + str(s) == h:
        t += 1
    s += 1
    if s == 60:
        a += 1
        s == 0
    if s < 10:
        k = ('0' + str(s))
    else:
        k = str(s)
    print(a, k)
print(t)
