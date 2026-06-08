n = int(input())
sx1 = 0
sx2 = 0
sx3 = 0
sx4 = 0
sx5 = 0
sx6 = 0
sc1 = 0
sc2 = 0
sc3 = 0
sc4 = 0
sc5 = 0
sc6 = 0
for i in range(1,(10**9)+1):
    si1 = i
    si2 = i
    si3 = i
    si4 = i
    si5 = i
    si6 = i    
    while si1 > 1:
        if si1 % 2 == 0:
            si1 = si1 / 2
            sx1 += 1
        elif sx1 > 0:
            sc1 = 2
        else:
            break
    while si2 > 1:
        if si2 % 3 == 0:
            si2 = c / 3
            sx2 += 1
        elif sx2 > 0:
            sc2 = 3
        else:
            break
    if (sx1 + 1)*(sx2 +1)*(sx3 + 1)*(sx4 +1)*(sx5 + 1) == n\
           and sc1 + sc2 + sc3 + sc4 + sc5  == i:
        print(i)
        break
    