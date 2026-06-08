n = int(input())
p = [0]*n
x = list(map(int, input().split()))
d = list(map(int, input().split()))
k = int(input()) - 1
r = 0
def explode(k):
    global r
    r += 1
    p[k] = -1
    for i in range(k+1, n):
        if p[i] != -1 and d[k] >= x[i] - x[k]:
            explode(i)
    for i in range(k-1, -1, -1):
        if p[i] != -1 and d[k] >= x[k] - x[i]:
            explode(i)
explode(k)
print(r)