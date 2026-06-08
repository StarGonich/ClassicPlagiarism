h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
res = 0
n1 = ['00', '01', '02', '03', '04', '05', '06', '07', '08', '09'] + [str(x) for x in range(10,61)]
for h in n1[h1:h2]:
    for m in n1[m1:m2]:
        if h == m:
            res += 1
        if h[::-1] == m:
            res += 1
        if h+m in ['2345','0124','1234']:
            res += 1
print(res)