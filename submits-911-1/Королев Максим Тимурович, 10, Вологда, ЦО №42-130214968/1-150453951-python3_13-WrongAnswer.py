h1, m1, h2, m2, count = input(), input(), input(), input(), 0
z = (int(h2) - int(h1)) * 60 + (int(m2) - int(m1)) + 1
for _ in range(z):
    if len(m1) != 2:
        m1 = f'0{m1}'
    if int(h1) == int(m1):
        count += 1
    elif h1[0] == m1[1] and h1[1] == m1[0]:
        count += 1
    elif int(h1) == int(m1) - 11:
        count += 1
    m1 = str(int(m1) + 1)
    if m1 == '60':
        h1 = str(int(h1) + 1)
        m1 = 00
print(count)
    
