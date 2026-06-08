def S():
    x=int(input())
    y=int(input())
    z=int(input())
    not_big=-10**9
    big=10**9
    if x==y:
        if z>=x:
            e=5*z-4*x
            if not_big <= e <= big:
                print(x,x,x,x,e)
                return
        if z<=x:
            a=5*z-4*x
            if not_big <= a <= big:
                print(a,x,x,x,x)
                return
        print(-1)
        return
    xy=5*z-2*x-3*y
    if xy>= 2:
        e=5*z-2*x-2*y-1
        if not_big <= e <= big and e!= x and (y+1)!= x:
            print(x,x,y,y+1,e)
            return
    if xy <=0:
        a=5*z-2*x-2*y+1
        if not_big <= a <= big and a!= x and (y-1)!= x:
            print(a,y-1,y,x,x)
            return
    print(-1)
if __name__=="__main__":
    S()