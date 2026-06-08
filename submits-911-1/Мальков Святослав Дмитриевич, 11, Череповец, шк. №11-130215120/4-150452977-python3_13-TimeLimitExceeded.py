# p>=n+1
# p<=n+k
n = int(input())
k = int(input())
p = n
e = {}
def NOK(n, m):
    n1 = n
    while True:
        if n1 % n == 0 and n1 % m == 0:
            break
        n1 = n1 + n
    return(n1)
        
        

        
        
    
for i in range(n + 1, n + k + 1):
    e[NOK(i, n)] = i
t = []
for i in e.keys():
    t.append(i)
print(e[min(t)])
    