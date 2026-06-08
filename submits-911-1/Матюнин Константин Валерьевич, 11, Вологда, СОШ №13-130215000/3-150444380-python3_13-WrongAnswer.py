N = int(input())
T = int(input())

a = []
ans = 0

for i in range(N):
    t1, t2 = map(int, input().split())
    a.append(t2-t1)
    for j in range(1, 100):
        if t1 > 3600*(j-1) and t2 < 3600*j and (t2-t1) > T:
            ans = t2-t1
            break
        else:
            ans = -1
            break
        
print(ans)