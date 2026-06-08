h1, m1, h2, m2 = int(input()), int(input()), int(input()), int(input())
count = 0
while (h1 != h2) or (m1 != m2):
    if h1 < 10:
        strh1 = '0'+str(h1)
    else:
        strh1 = str(h1)
    if m1 < 10:
        strm1 = '0'+str(m1)
    else:
        strm1 = str(m1)

    if h1 == m1:
        count += 1
    elif strh1 == strm1[1] + strm1[0]:
        count += 1
    elif int(strh1[0]) == int(strh1[1]) - 1 and int(strh1[0]) == int(strm1[0]) - 2 and int(strh1[0]) == int(strm1[1]) - 3:
        count += 1

    m1 += 1
    if m1 == 60:
        m1 = 0
        h1 += 1
    if h1 == 24:
        h1 = 0
print(count)