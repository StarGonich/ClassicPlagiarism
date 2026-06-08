a = int(input())
b = int(input())
x = int(input())
y = int(input())
k = 0
if b != 0:
    b -= 1
else:
    a -= 1
    b = 59
while a != x or b != y:
    if b != 59:
        b += 1
    else:
        a += 1
        b = 0
    aa = a
    bb = b
    if a < 10:
        a = '0' + str(a)
    if b < 10:
        b = '0' + str(b)
    if b == a or (str(b)[0] == str(a)[1] and str(a)[0] == str(b)[1]) or (str(a)[0] < str(a)[1] and str(a)[1] < str(b)[0] and str(b)[0] < str(b)[1]):
        k += 1
    a = aa
    b = bb
print(k)