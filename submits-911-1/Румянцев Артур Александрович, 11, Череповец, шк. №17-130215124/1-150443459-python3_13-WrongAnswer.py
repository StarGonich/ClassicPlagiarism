h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

count = 0
ch = h1
chh = h1-1
cm = m1

if len(str(h1))<2:
    h1 = '0' + str(h1)
if len(str(m1))<2:
    m1 = '0' + str(m1)
if len(str(h2))<2:
    h2 = '0' + str(h2)
if len(str(m2))<2 < 10:
    m2 = '0' + str(m2)
    
h11 = str(h1)[:1]
h12 = str(h1)[1:]
m11 = str(m1)[:1]
m12 = str(m1)[1:]

m1rvrsd = str(m12) + str(m11)
if h1 == h2 and m1 == m2:
    if h1 == m1 or str(h1).endswith(m1rvrsd) or (int(h11) == int(h12)-1 and int(h12) == int(m11)-1 and int(m11) == int(m12)-1):
        print('1')
    else: print('0')
else:
    while int(chh) < int(h2):
        if len(str(ch))<2:
                ch = '0' + str(ch)
        while int(cm) <60:
            if len(str(cm))<2:
                cm = '0' + str(cm)
            ch1 = str(ch)[:1]
            ch2 = str(ch)[1:]
            cm1 = str(cm)[:1]
            cm2 = str(cm)[1:]
            cmrvrsd = str(cm2) + str(cm1)
            if ch == cm or str(ch) == cmrvrsd or (int(ch1) == int(ch2)-1 and int(ch2) == int(cm1)-1 and int(cm1) == int(cm2)-1):
                count += 1
                cm = int(cm)
                cm+=1
            else:
                cm = int(cm)
                cm+=1
        chh = int(chh)
        chh+=1
        ch = int(ch)
        ch+=1
    print(count)
