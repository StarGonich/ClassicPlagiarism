#Короче, я не успеваю сделать задание, так что просто скину игру "Жизнь" которую сделал пока решал


loadout = [0, 0, 0, 0, 0, 0, 0,
           0, 0, 1, 0, 0, 0, 0,
           0, 0, 0, 1, 0, 0, 0,
           0, 1, 1, 1, 0, 0, 0,
           0, 0, 0, 0, 0, 0, 0,
           0, 0, 0, 0, 0, 0, 0,
           0, 0, 0, 0, 0, 0, 0]
w = 7
h = 7
h1 = h-1
step = 1
rtd = []
rtb = []

print('Step: '+str(step))
print(loadout[:7])
print(loadout[7:14])
print(loadout[14:21])
print(loadout[21:28])
print(loadout[28:35])
print(loadout[35:42])
print(loadout[42:49])
    
while step < 20:
    for pos in range(w*h):
        life_around = 0
        try:
            c1 = loadout[(pos-h)-1]
            if (pos-h)-1 < 0:
                c1 = 0
        except: c1=0
        try:
            c2 = loadout[pos-h]
            if pos-h < 0:
                c2=0
        except: c2=0
        try:
            c3 = loadout[(pos-h)+1]
            if (pos-h)+1 < 0:
                c3=0
        except: c3=0
        try:
            c4 = loadout[pos-1]
            if pos-1 < 0:
                c4=0
        except: c4=0
        try:
            c5 = loadout[pos+1]
            if pos+1 < 0:
                c5=0
        except: c5=0
        try:
            c6 = loadout[(pos+h)-1]
            if pos+h-1 < 0:
                c6=0
        except: c6=0
        try:
            c7 = loadout[pos+h]
            if pos+h < 0:
                c7=0
        except: c7=0
        try:
            c8 = loadout[(pos+h)+1]
            if (pos+h)+1 < 0:
                c8=0
        except: c8=0
        #print('pos: ', pos, ' | ',c1,c2,c3,c4,c5,c6,c7,c8)
     
        if c1 == 1:
            life_around += 1
        if c2 == 1:
            life_around += 1
        if c3 == 1:
            life_around += 1
        if c4 == 1:
            life_around += 1
        if c5 == 1:
            life_around += 1
        if c6 == 1:
            life_around += 1
        if c7 == 1:
            life_around += 1
        if c8 == 1:
            life_around += 1
        if loadout[pos] == 1:
            if life_around == 3 or life_around == 2:
                pass
            else:
                rtd.append(pos)
        else:
            if life_around == 3:
                rtb.append(pos)
            else:
                pass
            
    for d in rtd:
        loadout[d]=0
    for b in rtb:
        loadout[b]=1
    rtd.clear()
    rtb.clear()
    step += 1
    print('Step: '+str(step))
    print(loadout[:7])
    print(loadout[7:14])
    print(loadout[14:21])
    print(loadout[21:28])
    print(loadout[28:35])
    print(loadout[35:42])
    print(loadout[42:49])
