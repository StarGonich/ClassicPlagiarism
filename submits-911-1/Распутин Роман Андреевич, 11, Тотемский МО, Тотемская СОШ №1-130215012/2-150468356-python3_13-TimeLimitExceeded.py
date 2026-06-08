n = int(input())
flag = True
for i in range(1, 10**9):
    c = i
    s = 1
    j = 1
    f = [1]
    for g in range(2, 10**5):
        if c % g == 0 and c >= g:
            s += g
            j += 1
            f += [g]
            c = c // g
    if j == n and s == i:
        print(i)
        print(*f[::-1])
        flag = False
        break
if flag == True:
    print(-1)