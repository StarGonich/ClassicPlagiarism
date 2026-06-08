N = int ( input())
T = int ( input())
b= True
a = []
k=0
tp=0
for i in range (10001):
    a.append (0)
for i in range (N):
    t1, t2 = map(int, input().split())
    for j in range (tp,t1):
        a[j] = k    
    for j in range (t1,t2):
        k+=1
        a[j] = k
    tp=t2
        
for i in range (3601, 10001):
    k= a[i]- a[i-3601]
    if k>T:
        b=False
        print(i-3600+1)
        break
if (b):
    print (-1)
