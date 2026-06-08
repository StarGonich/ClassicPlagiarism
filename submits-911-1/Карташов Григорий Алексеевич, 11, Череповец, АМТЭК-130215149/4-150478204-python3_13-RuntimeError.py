from math import lcm, gcd
def dels(n):
    s = []
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            if i**2 == n:
                ans.append(i)
            else:
                ans.append(i)
                ans.append(n//i)
    return ans
n = int(input())
k = int(input())
ans = []
if n + k > 2* n:
    print(2 * n)
else:
    c = 1
    s = dels(n)
    i = len(s) - 1
    q = 0
    while True:
        if c > k:
            print(n * (n + q) // n)
            break
        q = c
        c*=s[i]
        i -= 1