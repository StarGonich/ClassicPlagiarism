h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k = 0
for i in range(h1, h2 + 1):
    for j in range(m1, m2 + 1):
        if i < 10:
            q = '0' + str(i)
        else:
            q = str(i)
        if j < 10:
            w = '0' + str(j)
        else:
            w = str(j)
        if i == j or q == w[1] + w[0] or (int(q[0]) == int(q[1]) - 1 and int(q[1]) == int(w[0]) - 1 and int(w[0]) == int(w[1]) - 1):
            k += 1
print(k)