n = int(input())
t = int(input())
m = []
v = []
for i in range(n):
    m.append([int(k) for k in input().split()])
j = 0
v = 99999
c = -1
for i in range(m[-1][1] - 3600):
    x = 0
    k = 0
    if i > m[j][1]:an = int(input())
t = int(input())
m = []
v = []
for i in range(n):
    m.append([int(k) for k in input().split()])
j = 0
v = 99999
c = -1
for i in range(3000, m[-1][1] - 3600):
    x = 0
    k = 0
    if i > m[j][1]:
        j += 1
    if m[j][0] <= j <= m[j][1]:
        x += min(3600, m[j][1] - i)
        k = 1
    o = i + 3600
    k += j
    while k < n and m[k][0] < o:
        x += min(o - m[k][0], m[k][1] - m[k][0])
        k += 1
    if t < x < v:
        v = x
        c = i
print(c)
        j += 1
    if m[j][0] <= j <= m[j][1]:
        x += min(3000, m[j][1] - i)
        k = 1
    o = i + 3600
    k += j
    while k < n and m[k][0] < o:
        x += min(o - m[k][0], m[k][1] - m[k][0])
        k += 1
    if t < x < v:
        v = x
        c = i
print(c)
