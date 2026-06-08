n = int(input())
x = list(map(int, input().split()))
d = list(map(int, input().split()))
k = int(input())
r = 0
def explode(k):
    global r
    r += 1
    x[k] = -1
    for i in range(k, n-1):
        if x[i] != -1 and d[i] >= x[i-1] - x[k]:
            explode(i)
    for i in range(k, -1, -1):
        if x[i] != -1 and d[i] >= x[k] - x[i]:
            explode(i)
explode(k)
print(r)