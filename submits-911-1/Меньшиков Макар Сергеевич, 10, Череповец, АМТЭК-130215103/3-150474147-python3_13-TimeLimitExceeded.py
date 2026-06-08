n = int(input())
t = int(input())
s = [0] * n
l = True
for i in range(n):
    a, b = map(int, input().split())
    l = [a] + [b]
    s[i] = list(l)
l = [0] * (s[n - 1][1] + 1)
for i in s:
    for j in range(i[0], i[1] + 1, 1):
        l[j] += 1
for i in range(s[0][0], s[n - 1][1] - 3599, 1):
    k = 0
    for j in range(i, i + 3599, 1):
        k += l[j]
    if k > t:
        print(i)
        l = False
        break
if l:
    print(-1)