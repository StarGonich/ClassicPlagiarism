h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
count = 0
if h1 == h2 and m1 == m2:
    h1 = h1 * 60
    h2 = h2 * 60
    hm1 = h1 + m1
    hm2 = h2 + m2  
    for h in range(hm1, hm2 + 1):
        hs = str(h)
        hh = h // 60
        mm = h % 60
        hhs = str(hh)
        mms = str(mm)
        if len(mms) == 1:
            mmss = '0' + mms
        else:
            mmss = mms
        hhs0 = int(hhs[0])
        hhs1 = int(hhs[1])
        mms0 = int(mmss[0])
        mms1 = int(mmss[1])
        if hh == mm or (hhs[0] == mmss[1] and hhs[1] == mmss[0]) or (hhs1 == hhs0 + 1 and mms0 == hhs1 + 1 and mms1 == mms0 + 1):
            count = 1
        
h1 = h1 * 60
h2 = h2 * 60
hm1 = h1 + m1
hm2 = h2 + m2

for h in range(hm1, hm2 + 1):
    hs = str(h)
    hh = h // 60
    mm = h % 60
    hhs = str(hh)
    mms = str(mm)
    if len(mms) == 1:
        mmss = '0' + mms
    else:
        mmss = mms
    hhs0 = int(hhs[0])
    hhs1 = int(hhs[1])
    mms0 = int(mmss[0])
    mms1 = int(mmss[1])
    if hh == mm or (hhs[0] == mmss[1] and hhs[1] == mmss[0]) or (hhs1 == hhs0 + 1 and mms0 == hhs1 + 1 and mms1 == mms0 + 1):
        count += 1

print(count)