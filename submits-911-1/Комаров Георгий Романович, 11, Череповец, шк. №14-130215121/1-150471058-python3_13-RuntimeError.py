h1 = str(input())
m1 = str(input())
h2 = str(input())
m2 = str(input())
count = 0
if (h1 == h2) and (m1 == m2):
    count += 1
for i in range(int(h1), int(h2) + 1):
    for j in range(int(m1), int(m2)):
        if i == j:
            count += 1
        if i[0] == j[0] and i[1] == j[1]:
            count += 1
        if i[0] == i[1] + 1 and i[1] == i[2] + 1 and i[2] == i[3] + 1:
            count += 1
print(count)


                  