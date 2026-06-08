n = int(input())
k = int(input())
a = []
l = []
mi = 9999999999999999999999999999999999999
for p in range(n+1,n+k+1):
    for i in range(max(n,p),99999999999999999999999):
        if i % n == 0 and i % p == 0:
            l = [i,p]
            a.append(l)
            break
for i in range(len(a)):
    if a[i][0] < mi:
        mi = a[i][0]
        op = a[i][1]
print(op)

