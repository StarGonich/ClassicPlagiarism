def solve():
    n = int(input().strip())
    
    if n == 1:
        print(1)
        print(1)
    elif n == 2:
        print(-1)
    elif n == 3:
        print(6)
        print("1 2 3")
    elif n == 4:
        print(12)
        print("1 2 3 6")
    elif n == 5:
        print(24)
        print("1 2 3 4 6 8")  
        print("12 8 3 1")  
    else:
       
        if n == 6:
            print(28)
            print("14 7 4 2 1")  
        
     
        m = 2 ** (n - 1) * 3
        print(m)
        
        
        divisors = [1]
        for i in range(1, n):
            divisors.append(2 ** i)
        print(" ".join(map(str, divisors[:n])))

if __name__ == "__main__":
    solve()