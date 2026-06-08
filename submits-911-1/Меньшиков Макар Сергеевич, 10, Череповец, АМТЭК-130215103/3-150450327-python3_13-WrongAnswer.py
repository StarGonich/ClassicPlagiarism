n = int(input())
t = int(input())
s = [0] * n
l = True
for i in range(n):
    a, b = map(int, input().split())
    l = [a] + [b]
    s[i] = list(l)
for i in range(s[0][0], s[n - 1][1] + 1, 1):
    k = 0
    for j in s:
        if j[0] >= i and j[1] <= i + 3600:
            k += j[1] - j[0]
        elif j[0] > i + 3600:
            k += 0
        elif j[1] < i:
            k += 0
        elif j[1] > i + 3600 and j[0] < i + 3600 and j[0] >= i:
            k += i + 3600 - j[0]
        elif j[0] < i and j[1] > i + 3600:
            k += 3600
        elif j[0] < i and j[1] < i + 3600 and j[1] > i:
            k += j[1] - i
    if k > t:
        l = False
        print(i)
        break
if l:
    print(-1)