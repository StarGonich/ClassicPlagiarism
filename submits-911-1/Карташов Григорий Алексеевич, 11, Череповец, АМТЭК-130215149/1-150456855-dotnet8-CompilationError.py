def first(h1, m1, h2, m2):
    if h1 >= m1:
        if m2 >= h2:
            q1 = (h2 - h1) + 1
        else:
            q1 = (h2 - h1)
    else:
        if m2 >= h2:
            q1 = (h2 - h1)
        else:
            q1 = (h2 - h1) - 1
    if q1 < 0:
        q1 = 0
        
    return q1
def second(h1, m1, h2, m2):
    if h1 == h2:
        if str(m1) <= str(h2)[::-1] and str(m2) >= str(h2)[::-1]:
            return 1
        return 0
    c = 0
    for i in range(h1 + 1, h2):
        z = str(i)
        if len(z) == 1:
            z += "0"
        else:
            z = z[::-1]
        if int(z) < 60:
            c += 1
        print(c, "TEST", i)
    z = is_good(h1)
    g = is_good(h2)
    if  z >=  (m1) and z < 60:
        c += 1
    if g >= (m2) and g < 60:
        c += 1    
    return c

def third(h1, m1, h2, m2):
    c = 0
    d = {1:23, 12:34, 23:45}
    if h1 == h2:
        if h1 in [1, 12, 23]:
            mins = d[h1]
            if m1 <= mins and m2 >= mins:
                return 1
    for i in range(h1, h2 + 1):
        if check(i, m1, m2):
            c += 1
    for i in (1, 12, 23):
        if h2 == i:
            if check2(i, m2):
                c += 0
            else:
                c -= 1
    if c > 3:
        return 3
    return c
        
def is_good(h):
    q = str(h)
    if len(q) == 1:
        q = q + "0"
    else:
        q = q[::-1]
    return int(q)
def check(i, m1, m2):
    if i == 1:
        return m1 < 24
    if i == 12:
        return m1 < 35
    if i == 23:
        return m1 < 46
def check2(i, m1):
    if i == 1:
        return m1 > 22
    if i == 12:
        return m1 > 33
    if i == 23:
        return m1 > 44    

a = int(input())
b = int(input())
c = int(input())
d = int(input())
print(first(a, b, c,d) + second(a, b, c, d) + third(a, b, c, d))