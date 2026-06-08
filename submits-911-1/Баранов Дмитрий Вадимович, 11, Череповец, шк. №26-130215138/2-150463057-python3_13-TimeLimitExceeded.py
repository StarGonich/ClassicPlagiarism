n = int(input())
def f(n):
    d = set()
    for i in range(1, int(n**0.5)+ 1):
        if n % i == 0:
            d.add(i)
            d.add(n // i)
    d.remove(n)
    return d
de = []
res = -1
for num in range(1,10**9):
    s = list(f(num))
    if n == len(s):
        if sum(s) == num:
            res = num
            for i in s[::-1]:
                de.append(i)
            break
if res != -1:
    print(res)
    print(*de)
else:
    prnt(res)
