a = int(input())
s = int(input())
d = int(input())
f = int(input())
t = 0
p = '0123'
h = '2345'
if s < 10:
    k = ('0' + str(s))
else:
    k = str(s)
g = (60 * d + f) - (60 * a + s)
if g < 0:
    g = 1440 + g
for i in range(g):
    if s > 59:
        a += 1
        s = 0
        k = ''
    if a < 10:
        w = '0' + str(a)
    else:
        w = str(a)
    if a == 24:
        a = 0
    if s < 10:
        k = ('0' + str(s))
    else:
        k = str(s)    
    if a == s:
        t += 1
    elif str(w) == (k[1] + k[0]):
        t += 1
    elif str(w) + str(s) == p or str(w) + str(s) == h:
        t += 1
    s += 1
   
print(t)