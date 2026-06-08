h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
cnt = 0

for i in range(h1, h1+1):
    for g in range(m1, m2+1):
        if i == g:
            cnt += 1
        if int(str(i)[::-1]) == int(str(g)):
            cnt += 1
        f = str(i)+str(g)
        if int(f[0])+1 == int(f[1]) and int(f[1])+1 == int(f[2]) and int(f[2])+1 == int(f[3]):
            cnt += 1


for i in range(h1+1, h2+1):
    for g in range(0, 61):
        if i == g:
            cnt += 1
        if int(str(i)[::-1]) == int(str(g)):
            cnt += 1
        f = str(i) + str(g)
        if int(f[0])+1 == int(f[1]) and int(f[1])+1 == int(f[2]) and int(f[2])+1 == int(f[3]):
            cnt += 1

print(cnt)

