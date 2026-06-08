def deli(n):
    res = []
    for i in range(1, int(n**0.5)+1):
        if n%i == 0:
            res.append(i)
            if n//i not in res:
                res.append(n//i)
    return res

n1 = int(input())
for n in range(1000000000):
    nd = deli(n)
    nd = sorted(nd)
    if len(nd) >= n1:
        if n == sum(nd[:n1]):
            print(sum(nd[:n1]))
            print(*nd[:n1])
            break