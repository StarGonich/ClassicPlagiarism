a = int(input())
b = int(input())
c = int(input())
d = int(input())
n = 0
for i in range(a,c+1):
    for u in range(b,d+1):
        h = i // 10
        j = i % 10
        p = str(u // 10)
        o = str(u % 10)
        l = o + p
        if i == u or i == int(l) or (h == j - 1 and j == int(p) - 1 and int(p) == int(o) - 1):
            n += 1
print(n)