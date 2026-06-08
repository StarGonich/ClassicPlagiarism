def solve():
    n = int(input().strip())
    
    if n == 1:
        print(1)
        print(1)
    elif n == 2:
        print(-1)
    else:
        
        
        m = 12
        all_divisors = [1, 2, 3, 4, 6, 12]
        
    
        if n == 3:
            print(6)
            print("1 2 3")
        elif n == 4:
            print(12)
            print("6 3 2 1")
        elif n == 5:
            print(24)
            print("12 8 3 1")
        else:
            
            m = 3 * (2 ** (n - 1))
            print(m)
            
            
            divisors = [2 ** i for i in range(n - 1)]
            divisors[-1] = 3 * (2 ** (n - 2))
            print(" ".join(map(str, divisors)))

if __name__ == "__main__":
    solve()