h1, m1, h2, m2 = input(), input(), input(), input()
def Check(h, m):
    flag = False
    if h == m:
        flag = True
    elif h == m[::-1]:
        flag = True
    else:
        flag = True
        s = h + m
        for i in range(len(s) - 1):
            if int(s[i + 1]) - int(s[i]) != 1:
                flag = False
    return flag

def r(n):
    if len(n) == 1:
        n = "0" + n
    return n

count = 0
h2, m2 = r(h2), r(m2)
while h1 != h2 or m1 != m2:
    h1 = r(h1)
    m1 = r(m1)
    if Check(h1, m1):
        count += 1
    m1 = r(str(int(m1) + 1))
    if m1 == "60":
        m1 = "00"
        h1 = r(str(int(h1) + 1))
    if h1 == "24":
        h1 = "00"
print(count)    
