n=int(input())
M=[1,2,3]
if n==1:
    print(1)
    print(1)
elif n==3:
    print(6)
    print(*M)
else:
    for i in range(n-3):
        M.append(M[-1]*2)
        ans*=M[-1]*2
    print(ans*6)
    print(*M)