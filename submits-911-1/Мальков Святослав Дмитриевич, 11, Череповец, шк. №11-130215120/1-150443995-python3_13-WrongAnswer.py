h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
def timefun(n, m):
    flag = True
    if len(str(m)) == 1:
        mstr = '0' + str(m)
    else:
        mstr = str(m)
    if len(str(n)) == 1:
        nstr = '0' + str(n)
    else:
        nstr = str(n)
    nmstr = nstr + mstr
    for i in range(3):
        if int(nmstr[i]) + 1 != int(nmstr[i + 1]):
            flag = False

    return(nstr, mstr, flag)
h = h1
m = m1-1
counter = 0
while ((h != h2) or (m != m2)):
    m = m + 1
    if m == 60:
        h = h + 1
        m = 0
    hstr, mstr, F = timefun(h, m)
    if hstr == mstr or hstr == mstr[::-1] or F == True:
        counter = counter + 1
print(counter)
    
