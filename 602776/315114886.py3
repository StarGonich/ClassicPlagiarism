n = int(input())

x = [int(x) for x in input().split()]
d = [int(x) for x in input().split()]

k = int(input()) - 1

interv = [[max(0, x[i] - d[i]), x[i] + d[i]] for i in range(n)]

main_int = interv[k][:]

l, r = k - 1, k + 1

c = 1
while l >= 0 and r < n:
    if l >= 0 and x[l] >= main_int[0]:
        main_int[0] = min(main_int[0], interv[l][0])
        main_int[1] = max(main_int[1], interv[l][1])
        l -= 1
        c+=1

    if r < n and x[r] <= main_int[1]:
        main_int[0] = min(main_int[0], interv[r][0])
        main_int[1] = max(main_int[1], interv[r][1])
        r += 1
        c+=1

    if x[l] < main_int[0] and x[r] > main_int[1]:
        break

while l >= 0:
    if l >= 0 and x[l] >= main_int[0]:
        main_int[0] = min(main_int[0], interv[l][0])
        main_int[1] = max(main_int[1], interv[l][1])
        l -= 1
        c+=1
    else:
        break

while r < n:
    if r < n and x[r] <= main_int[1]:
        main_int[0] = min(main_int[0], interv[r][0])
        main_int[1] = max(main_int[1], interv[r][1])
        r += 1
        c+=1
    else:
        break


print(c)
