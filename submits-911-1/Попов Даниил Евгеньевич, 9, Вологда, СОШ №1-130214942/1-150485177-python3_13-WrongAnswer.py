h1 = input()
m1 = input()
h2 = input()
m2 = input()
c = 0
    
for h in range(int(h1), int(h2)+1):
    if int(h) < 10:
        h = "0" + str(h)
    else:
        h = str(h)
    if len(h) == 3:
        h = h[-2:]
    if h == h1:
        for m in range(int(m1), 60):
            if int(m) < 10:
                m = "0" + str(m)
            else:
                m = str(m)
            print(h,m)
            if h == m or (h[0] == m[1] and h[1] == m[0]) or (int(h[0])+1 == int(h[1]) and int(h[1])+1 == int(m[0]) and int(m[0])+1 == int(m[1])):
                c += 1
                print("here")
    elif h == h2:
        for m in range(0, int(m2)+1):
            if int(m) < 10:
                m = "0" + str(m)
            else:
                m = str(m)
            print(h,m)
            if h == m or (h[0] == m[1] and h[1] == m[0]) or (int(h[0])+1 == int(h[1]) and int(h[1])+1 == int(m[0]) and int(m[0])+1 == int(m[1])):
                c += 1
                print("here")            
    else:
        for m in range(0, 60):
            if int(m) < 10:
                m = "0" + str(m)
            else:
                m = str(m)
            print(h,m)
            if h == m or (h[0] == m[1] and h[1] == m[0]) or (int(h[0])+1 == int(h[1]) and int(h[1])+1 == int(m[0]) and int(m[0])+1 == int(m[1])):
                c += 1
                print("here")
            
print(c)
