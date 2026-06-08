n = int(input())
x = list(map(int, input().split()))
o = []
k = 0
while k < n - 1:
    if (x[k+1] - x[k]) == 1:
        o.append([k+1, 1])
        if len(o) > 2:
            print(-1)
            break
        for j in range(k, n-1):
            if x[j+1] - x[j] == 1:
                o[len(o)-1][1] += 1
                if j != n-2: continue
            k += o[len(o)-1][1] - 1
            break
    k += 1

if len(o) < 2:
    print(-1)
elif len(o) == 2:
    for i in o:
        print(i[0], i[1])