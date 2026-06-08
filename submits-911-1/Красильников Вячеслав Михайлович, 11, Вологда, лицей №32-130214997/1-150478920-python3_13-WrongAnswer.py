h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
al = '0123456789'
cnt = 0
if m1 > m2:
    rz1 = 60 - m1 + m2
else:
    rz1 = m2-m1
if h1 > h2:
    rz = 24-h1 + h2
else:
    rz = h2-h1
for i in range(rz+1):
    if h1 + i > 23:
        h1 = 0
    for j in range(rz1+1):
        if m1 + j > 59:
            m1 = 0
        if h1+i == m1 + j:
            cnt += 1
        if len(str(m1)) == 1 and len(str(h1)) == 2:
            if str(h1+i) == ('0' + str(m1+j))[::-1]:
                cnt +=1
        if len(str(h1)) == 1 and len(str(m1)) == 2:
            if ('0' + str(h1+i)) == str(m1+j)[::-1]:
                cnt +=1
        if len(str(h1)) ==1 and len(str(m1)) ==1:
            if '0' + str(h1+i) == ('0' + str(m1+j))[::-1]:
                cnt +=1
        if len(str(m1)) == 2 and len(str(h1)) == 2:
            if str(h1+i) == str(m1+j)[::-1]:
                cnt +=1
        if str(h1+i)+str(m1+j) in al:
            cnt+=1
print(cnt)