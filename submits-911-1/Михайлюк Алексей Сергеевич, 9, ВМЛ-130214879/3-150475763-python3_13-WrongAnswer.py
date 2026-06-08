n = int(input())
t = int(input())
m = []
v = [0]
for i in range(n):
    m.append([int(k) for k in input().split()])
j = 0
for i in range(m[-1][1]):
    if i > m[j][1]:
        j += 1
    if m[j][0] <= i < m[j][1]:
        v.append(v[i] + 1)
    else:
        v.append(v[i])
mi = 9999
c = -1
for i in range(m[-1][1] - 3600):
    if mi == t + 1:
        break
    z = v[i + 3600] - v[i]
    if t < z < mi:
        mi = z
        c = i
print(c)
