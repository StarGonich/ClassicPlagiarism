n=int(input())
result = find_number_with_divisors(n)
def find_number_with_divisors(n):
    if n==1:
        return -1
    m=2**(n-1)
    divisors=[2**i for i in range(n-1)]
    divisors.append(m)
    if sum(divisors[:-1]) == divisors[-1]:
        return m, divisors[:-1]
    return -1
if result==-1:
    print(-1)
else:
    m, divisors=result
    print(m)
    print(" ".join(map(str, divisors)