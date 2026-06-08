n=int(input())
t=int(input())
for i in range (1,n+1):
    t1, t2 = map(int, input().split())
    if (t2-t1+t1/t1)>t:
        print(n*(t+t2-t1))
    else:
        print(-1)
    
    
    
        