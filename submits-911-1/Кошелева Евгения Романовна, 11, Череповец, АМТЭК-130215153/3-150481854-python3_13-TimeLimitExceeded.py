N = int ( input())
T = int ( input())
b= True
a = []
for i in range (10001):
    a.append (0)
for i in range (N):
    t1, t2 = map(int, input().split())
    for j in range (t1,t2):
        a[j] = 1
        
for i in range (10001-3600):
    k= 0
    for j in range (3600):
        k+= a[i+j]
    if k>T:
        b=False
        print(i)
        break
if (b):
    print (-1)