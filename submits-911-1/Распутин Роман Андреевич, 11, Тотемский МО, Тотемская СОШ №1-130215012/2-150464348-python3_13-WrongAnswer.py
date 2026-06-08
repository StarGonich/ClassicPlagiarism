n = int(input())
flag = True
for i in range(1, 10**9):
    c = i
    s = 1
    j = 1
    f = [1]
    if c % 2 == 0:
        s += 2
        c = c // 2
        j += 1
        f += [2]
    if c % 3 == 0:
        s += 3
        c = c // 3
        j += 1
        f += [3]
    if c % 4 == 0:
        s += 4
        c = c // 4
        j += 1
        f += [4]
    if c % 5 == 0:
        s += 5
        c = c // 5
        j += 1
        f += [5]
    if c % 6 == 0:
        s += 6
        c = c // 6
        j += 1
        f += [6]
    if c % 7 == 0:
        s += 7
        c = c // 7
        j += 1
        f += [7]
    if c % 8 == 0:
        s += 8
        c = c // 8
        j += 1
        f += [8]
    if c % 9 == 0:
        s += 9
        c = c // 9
        j += 1
        f += [9]
    if j == n and s == i:
        print(i)
        print(*f[::-1])
        flag = False
        break
    if i > 9*8*7*6*5*4*3*2 and flag == True:
        print(-1)
        break