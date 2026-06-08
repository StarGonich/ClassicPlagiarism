h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
res = 0
n1 = ['00', '01', '02', '03', '04', '05', '06', '07', '08', '09'] + [str(x) for x in range(10,61)]
h = h1
m = m1
while n1[h]+n1[m] != n1[h2]+n1[m2]:
    h3 = n1[h]
    m3 = n1[m]
    if h3 == m3:
        res += 1
    if h3[::-1] == m3:
        res += 1
    if h3+m3 in ['2345','0124','1234']:
        res += 1
    m += 1
    if m == 60:
        h += 1
print(res)