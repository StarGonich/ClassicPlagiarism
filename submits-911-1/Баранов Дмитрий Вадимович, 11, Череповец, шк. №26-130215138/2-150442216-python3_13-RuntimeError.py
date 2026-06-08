n = int(input())
def f(n):
    d = set()
    for i in range(1, int(n**0.5)+ 1):
        if n % i == 0:
            d.add(i)
            d.add(n // i)
        d.remove(n)
    return d
res = -1
for num in range(1,10**9):
    s = f(num)
    if n == len(s):
        if sum(s) == num:
            res = num
            de = s
if res != -1:
    print(res, de)
else:
    prnt(res)

