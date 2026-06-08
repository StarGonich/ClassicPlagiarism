n = int(input())
x = list(map(int, input().split()))
o = []
k = 0
while k < n - 1:
    if (x[k+1] - x[k]) == 1:
        o.append([k+1, 1])
        for j in range(k, n-1):
            if x[j+1] - x[j] == 1:
                o[len(o)-1][1] += 1
                if j != n-2: continue
            k += o[len(o)-1][1] - 1
            break
    k += 1

if len(o) == 1:
    print(-1)
elif len(o) == 2:
    for i in range(len(o)-1):
        if abs(x[o[i + 1][0] - 1] - x[o[i][0] + o[i][1] - 2]) == 1 or abs(x[o[i + 1][0] + o[i + 1][1] - 2] - x[o[i][0] - 1]) == 1:
            print(o[i][0], o[i][1])
            print(o[i+1][0], o[i+1][1])
            break
        print(-1)