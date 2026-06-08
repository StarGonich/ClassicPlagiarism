
def nod(a,b):
    while b:
        a, b =b, a%b
    return a
def nok(a,b):
    return(abs(a*b)//nod(a,b))

n = int(input())
k = int(input())
mi = 10000000  
for p in range(1, 1000001):
    if p>=n + 1 and p<=n+k:
        no = nok(n,p)
        print(no)
        if no<mi:
            mi=no
print(mi)