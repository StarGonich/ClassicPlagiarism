f = True
n = int(input())
for i in range(1, 10**9+1):
    x = 0
    x1 = 0
    for d in range(1, 2//i+1):
        if i%d == 0:
            x += d
            x1 += 1
            #print(i,d)
    #print(x, x1, "--")
    if x == i and x1 == n:
        f = False
        break
if f == False:
    print(i)
    for d in range(1, i):
        if i%d == 0:
            print(d, end = " ")

else: print(-1)