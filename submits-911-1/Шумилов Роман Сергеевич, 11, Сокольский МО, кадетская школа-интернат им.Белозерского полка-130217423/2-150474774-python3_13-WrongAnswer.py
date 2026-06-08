def g():
    n=int(input().strip())
    if n==1:
        print(1)
        print(1)
    elif n==2:
        print(6)
        print('1 2 3')
    else:
        num=3*(2**(n-1))
        div=[]
        for i in range(n-1):
            div.append(2**i)
        div.append(3*(2**(n-2)))
        print(num)
        print(' '.join(map(str,div)))
if __name__ == '__main__':
    g()
        
