a = int(input())
b = int(input())
x = int(input())
y = int(input())
k = 0
bbb = b
if x == a:
    while b <= y:
        bb = b
        aa = a
        if a < 10:
            a = '0' + str(a)
        if b < 10:
            b = '0' + str(b)
        if b == a or (str(b)[0] == str(a)[1] and str(a)[0] == str(b)[1]) or (int(str(a)[0]) + 1 == int(str(a)[1]) and int(str(a)[1]) + 1 == int(str(b)[0]) and int(str(b)[0]) + 1 == int(str(b)[1])):
            k += 1
        a = aa
        b = bb
        b += 1
else:
    while b > 0 and b <= 59 and a != x:
        bb = b
        aa = a
        if a < 10:
            a = '0' + str(a)
        if b < 10:
            b = '0' + str(b)
        if b == a or (str(b)[0] == str(a)[1] and str(a)[0] == str(b)[1]) or (int(str(a)[0]) + 1 == int(str(a)[1]) and int(str(a)[1]) + 1 == int(str(b)[0]) and int(str(b)[0]) + 1 == int(str(b)[1])):
            k += 1
        a = aa
        b = bb
        b += 1
    b = 0
    while b <= y and a != x:
        bb = b
        xx = x
        if x < 10:
            x = '0' + str(x)
        if b < 10:
            b = '0' + str(b)
        if b == x or (str(b)[0] == str(x)[1] and str(x)[0] == str(b)[1]) or (int(str(x)[0]) + 1 == int(str(x)[1]) and int(str(x)[1]) + 1 == int(str(b)[0]) and int(str(b)[0]) + 1 == int(str(b)[1])):
            k += 1
        x = xx
        b = bb
        b += 1

    if x < a:
        xxx = x
        x = 23
        yyy = y
        y = 59
        b = 0
        while b <= y:
            bb = b
            xx = x
            if x < 10:
                x = '0' + str(x)
            if b < 10:
                b = '0' + str(b)
            if b == x or (str(b)[0] == str(x)[1] and str(x)[0] == str(b)[1]) or (int(str(x)[0]) + 1 == int(str(x)[1]) and int(str(x)[1]) + 1 == int(str(b)[0]) and int(str(b)[0]) + 1 == int(str(b)[1])):
                k += 1
            x = xx
            b = bb
            b += 1

        b = bbb
        aa = a
        if b > 0:
            a += 1
        if a == 24:
            a = 0        
        if a <= 1 and x >= 2:
            k += 1
        if a <= 12 and x >= 13:
            k += 1
        if a < x and a <= 15:
            k += 2 * (min(x, 16) - a)
        a = aa
        a = 0
        b = 0
        x = xxx
        y = yyy
        if b > 0:
            a += 1
        if a == 24:
            a = 0
        if a <= 1 and x >= 2:
            k += 1
        if a <= 12 and x >= 13:
            k += 1
        if a < x and a <= 15:
            k += 2 * (min(x, 16) - a)        
print(k)