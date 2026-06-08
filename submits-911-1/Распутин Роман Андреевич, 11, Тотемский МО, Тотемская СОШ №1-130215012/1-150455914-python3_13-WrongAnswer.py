h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
cnt = 0
if (h2 - h1) > 1:
    for i in range(h1, h1+1):
        for g in range(m1, 60):
            if int(i) <= 9 and int(g) >= 10:
                i1 = '0' + str(i)
                g1 = str(g)
            if int(i) <= 9 and int(g) <= 9:
                i1 = '0' + str(i)
                g1 = '0' + str(g)
            if int(i) >= 10 and int(g) <= 9:
                i1 = str(i)
                g1 = '0' + str(g)
            if int(i) >= 10 and int(g) >= 10:
                i1 = str(i)
                g1 = str(g)
            if i1 == g1 or i1[::-1] == g1:
                cnt += 1
            f = str(i1) + str(g1)
            if int(f[0])+1 == int(f[1]) and int(f[1])+1 == int(f[2]) and int(f[2])+1 == int(f[3]):
                cnt += 1
    for i in range(h1+1, h2):
        for g in range(0, 60):
            if int(i) <= 9 and int(g) >= 10:
                i1 = '0' + str(i)
                g1 = str(g)
            if int(i) <= 9 and int(g) <= 9:
                i1 = '0' + str(i)
                g1 = '0' + str(g)
            if int(i) >= 10 and int(g) <= 9:
                i1 = str(i)
                g1 = '0' + str(g)
            if int(i) >= 10 and int(g) >= 10:
                i1 = str(i)
                g1 = str(g)
            if i1 == g1 or i1[::-1] == g1:
                cnt += 1
            f = str(i1) + str(g1)
            if int(f[0]) + 1 == int(f[1]) and int(f[1]) + 1 == int(f[2]) and int(f[2]) + 1 == int(f[3]):
                cnt += 1
    for i in range(h2, h2+1):
        for g in range(0, m2+1):
            if int(i) <= 9 and int(g) >= 10:
                i1 = '0' + str(i)
                g1 = str(g)
            if int(i) <= 9 and int(g) <= 9:
                i1 = '0' + str(i)
                g1 = '0' + str(g)
            if int(i) >= 10 and int(g) <= 9:
                i1 = str(i)
                g1 = '0' + str(g)
            if int(i) >= 10 and int(g) >= 10:
                i1 = str(i)
                g1 = str(g)
            if i1 == g1 or i1[::-1] == g1:
                cnt += 1
            f = str(i1) + str(g1)
            if int(f[0]) + 1 == int(f[1]) and int(f[1]) + 1 == int(f[2]) and int(f[2]) + 1 == int(f[3]):
                cnt += 1
if (h2 - h1) == 0:
    for i in range(h1, h2+1):
        for g in range(m1, m2+1):
            if int(i) <= 9 and int(g) >= 10:
                i1 = '0' + str(i)
                g1 = str(g)
            if int(i) <= 9 and int(g) <= 9:
                i1 = '0' + str(i)
                g1 = '0' + str(g)
            if int(i) >= 10 and int(g) <= 9:
                i1 = str(i)
                g1 = '0' + str(g)
            if int(i) >= 10 and int(g) >= 10:
                i1 = str(i)
                g1 = str(g)
            if i1 == g1 or i1[::-1] == g1:
                cnt += 1
            f = str(i1) + str(g1)
            if int(f[0]) + 1 == int(f[1]) and int(f[1]) + 1 == int(f[2]) and int(f[2]) + 1 == int(f[3]):
                cnt += 1
if (h2 - h1) == 1:
    for i in range(h1, h2):
        for g in range(m1, 60):
            if int(i) <= 9 and int(g) >= 10:
                i1 = '0' + str(i)
                g1 = str(g)
            if int(i) <= 9 and int(g) <= 9:
                i1 = '0' + str(i)
                g1 = '0' + str(g)
            if int(i) >= 10 and int(g) <= 9:
                i1 = str(i)
                g1 = '0' + str(g)
            if int(i) >= 10 and int(g) >= 10:
                i1 = str(i)
                g1 = str(g)
            if i1 == g1 or i1[::-1] == g1:
                cnt += 1
            f = str(i1) + str(g1)
            if int(f[0]) + 1 == int(f[1]) and int(f[1]) + 1 == int(f[2]) and int(f[2]) + 1 == int(f[3]):
                cnt += 1
    for i in range(h2, h2+1):
        for g in range(0, m2+1):
            if int(i) <= 9 and int(g) >= 10:
                i1 = '0' + str(i)
                g1 = str(g)
            if int(i) <= 9 and int(g) <= 9:
                i1 = '0' + str(i)
                g1 = '0' + str(g)
            if int(i) >= 10 and int(g) <= 9:
                i1 = str(i)
                g1 = '0' + str(g)
            if int(i) >= 10 and int(g) >= 10:
                i1 = str(i)
                g1 = str(g)
            if i1 == g1 or i1[::-1] == g1:
                cnt += 1
            f = str(i1) + str(g1)
            if int(f[0]) + 1 == int(f[1]) and int(f[1]) + 1 == int(f[2]) and int(f[2]) + 1 == int(f[3]):
                cnt += 1
print(cnt)