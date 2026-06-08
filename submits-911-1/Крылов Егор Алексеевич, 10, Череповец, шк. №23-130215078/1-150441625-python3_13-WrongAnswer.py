h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
total = 0
hh = h1 * 60
tt = hh + m1
hh1 = h2 * 60
tt1 = hh1 + m2
print(tt, tt1)
if tt < tt1:
    c = tt1 - tt
    c1 = 1
    while c1 != c:
        c1+= 1
        if c1 == h1:
            total += 1
print(total)