h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
x = h1 * 60 + m1
y = h2 * 60 + m2
for a in range(x, y + 1):
    i = a // 60
    j = a % 60
    if i < 10:
        q = '0' + str(i)
    else:
        q = str(i)
    if j < 10:
        w = '0' + str(j)
    else:
        w = str(j)
    if (i == j) or (q == w[1] + w[0]) or (int(q[0]) == int(q[1]) - 1 and int(q[1]) == int(w[0]) - 1 and int(w[0]) == int(w[1]) - 1):
        k += 1
print(k)