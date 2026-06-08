def nod(a,b):
    while b:
        a, b =b, a%b
    return a
def nok(a,b):
    return(abs(a*b)//nod(a,b))

n = int(input())
k = int(input())
mi = float('inf')
ans = -1
for p in range(n+1, n+k+1):
    no = nok(n, p)
    if no< mi:
        mi=no
        ans=p
print(ans)