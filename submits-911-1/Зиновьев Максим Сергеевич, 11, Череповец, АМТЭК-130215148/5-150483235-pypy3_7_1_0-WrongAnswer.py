k = int(input())
n = int(input())
m = int(input())
a = [0] * n
f = False
x = ''
for p in range(k):
    for i in range(n):
        x = x + input()
    x = x.replace(' ', '')
    if int(x) != 0:
        f = True
        break
if f == True and p == 0:
    o = '1' + ' ' + '2'
    print(o)
else:
    o = '2' + ' ' + '1'
    print(o)
    