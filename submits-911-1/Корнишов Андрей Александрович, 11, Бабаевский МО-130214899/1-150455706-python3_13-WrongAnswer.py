h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
c = 0
h = h1
m = m1
while str(h)+str(m)!= str(h2)+str(m2):
    if h == m or h == m*10 or m == h+1:
        c += 1
    m += 1
    if m > 59:
        h += 1
        m = 0
    if h > 23:
        h = 0
    print(h,m)
print(c)