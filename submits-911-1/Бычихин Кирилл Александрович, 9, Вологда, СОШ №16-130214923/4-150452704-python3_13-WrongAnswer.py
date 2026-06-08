n = int(input())
k = int(input())

def gd(x):
    d = set()#множество делителей
    i = 1
    while (i*i <= x):
        if x % i == 0:
            d.add(i)
            d.add(x // i)
        i += 1
    return d

l = gd(n)
ml = None
answer = None

for d in l:
    p = ((n + 1) + d - 1) // d * d
    if (p<=n+k):
        gcd = d#наименьшее общее кратное
        t = p
        lcm = (n//gcd) * t
        min_lcm = None
        if ((min_lcm is None) or (lcm<min_lcm)):
            min_lcm = lcm
            answer = t

print(answer)