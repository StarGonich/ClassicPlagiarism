n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
k = int(input())
mi = a[k-1] - b[k-1]
ma = a[k-1] + b[k-1]
l = r = k - 1
q = 1
s = 1
while q:
    q = 0
    if l - 1 >= 0 and mi <= a[l-1] <= ma:
        mi = min(a[l-1]-b[l-1], mi)
        ma = max(a[l-1]+b[l-1], ma)
        l -= 1
        s += 1
    if r + 1 < n and mi <= a[r+1] <= ma:
        mi = min(a[r+1]-b[r+1], mi)
        ma = max(a[r+1]+b[r+1], ma)
        r += 1
        q = 1
        s += 1
print(s)