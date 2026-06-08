h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
cnt = 0
if h2 - h1 > 1:
    for i in range(h1, h1+1):
        for g in range(m1, 61):
            if i < 10 and g >= 10:
                i = '0' + str(i)
                g = str(g)
            if i < 10 and g < 10:
                i = '0' + str(i)
                g = '0' + str(g)
            if i > 9 and g < 10:
                i = str(i)
                g = '0' + str(g)
            if i > 9 and g > 9:
                i = str(i)
                g = str(g)
            if i == g:
                cnt += 1
            if i[::-1] == g:
                cnt += 1
            f = str(i) + str(g)
            if int(f[0])+1 == int(f[1]) and int(f[1])+1 == int(f[2]) and int(f[2])+1 == int(f[3]):
                cnt += 1

    for i in range(h1+1, h2):
        for g in range(0, 61):
            if i < 10 and g >= 10:
                i = '0' + str(i)
                g = str(g)
            if i < 10 and g < 10:
                i = '0' + str(i)
                g = '0' + str(g)
            if i > 9 and g < 10:
                i = str(i)
                g = '0' + str(g)
            if i > 9 and g > 9:
                i = str(i)
                g = str(g)
            if i == g:
                cnt += 1
            if i[::-1] == g:
                cnt += 1
            f = str(i) + str(g)
            if int(f[0]) + 1 == int(f[1]) and int(f[1]) + 1 == int(f[2]) and int(f[2]) + 1 == int(f[3]):
                cnt += 1

    for i in range(h2, h2+1):
        for g in range(0, m2+1):
            if i < 10 and g >= 10:
                i = '0' + str(i)
                g = str(g)
            if i < 10 and g < 10:
                i = '0' + str(i)
                g = '0' + str(g)
            if i > 9 and g < 10:
                i = str(i)
                g = '0' + str(g)
            if i > 9 and g > 9:
                i = str(i)
                g = str(g)
            if i == g:
                cnt += 1
            if i[::-1] == g:
                cnt += 1
            f = str(i) + str(g)
            if int(f[0]) + 1 == int(f[1]) and int(f[1]) + 1 == int(f[2]) and int(f[2]) + 1 == int(f[3]):
                cnt += 1
if h2 - h1 == 0:
    for i in range(h1, h2+1):
        for g in range(m1, m2+1):
            if i < 10 and g >= 10:
                i = '0' + str(i)
                g = str(g)
            if i < 10 and g < 10:
                i = '0' + str(i)
                g = '0' + str(g)
            if i > 9 and g < 10:
                i = str(i)
                g = '0' + str(g)
            if i > 9 and g > 9:
                i = str(i)
                g = str(g)
            if i == g:
                cnt += 1
            if i[::-1] == g:
                cnt += 1
            f = str(i) + str(g)
            if int(f[0]) + 1 == int(f[1]) and int(f[1]) + 1 == int(f[2]) and int(f[2]) + 1 == int(f[3]):
                cnt += 1
if h2 - h1 == 1:
    for i in range(h1, h2):
        for g in range(m1, 61):
            if i < 10 and g >= 10:
                i = '0' + str(i)
                g = str(g)
            if i < 10 and g < 10:
                i = '0' + str(i)
                g = '0' + str(g)
            if i > 9 and g < 10:
                i = str(i)
                g = '0' + str(g)
            if i > 9 and g > 9:
                i = str(i)
                g = str(g)
            if i == g:
                cnt += 1
            if i[::-1] == g:
                cnt += 1
            f = str(i) + str(g)
            if int(f[0]) + 1 == int(f[1]) and int(f[1]) + 1 == int(f[2]) and int(f[2]) + 1 == int(f[3]):
                cnt += 1
    for i in range(h2, h2+1):
        for g in range(0, m2+1):
            if i < 10 and g >= 10:
                i = '0' + str(i)
                g = str(g)
            if i < 10 and g < 10:
                i = '0' + str(i)
                g = '0' + str(g)
            if i > 9 and g < 10:
                i = str(i)
                g = '0' + str(g)
            if i > 9 and g > 9:
                i = str(i)
                g = str(g)
            if i == g:
                cnt += 1
            if i[::-1] == g:
                cnt += 1
            f = str(i) + str(g)
            if int(f[0]) + 1 == int(f[1]) and int(f[1]) + 1 == int(f[2]) and int(f[2]) + 1 == int(f[3]):
                cnt += 1
print(cnt)
