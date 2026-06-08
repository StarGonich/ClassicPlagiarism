a = []
b = []
for i in range(4):
    a.append(int(input()))
    b.append(a[i])

k = 0

i = b[0]

while i != b[2]:
    
    if len(str(i)) == 1:
        a[0] = '0' + str(i)
    else:
        a[0] = str(i)
                   
    if i == b[0]:
        for j in range(b[1], 55):
            if len(str(j)) == 1:
                q = '0' + str(j)
            else:
                q = str(j)
                
            if a[0][0] == q[1] and a[0][1] == q[0]:
                k += 1
            if int(a[0][0]) + 1 == int(a[0][1]) and int(a[0][0]) + 1 == int(q[0]) and int(q[0]) + 1 == int(q[1]):
                k += 1
            if a[0] == q:
                k += 1
            if int(a[0][0]) == int(a[0][1]) and int(a[0][0]) == int(q[0]) and int(q[0]) == int(q[1]):
                k -= 1
    
    if (i > b[0] and i < b[2]) or (i < b[0] and i < b[2]):
        for j in range(0,55):
            if len(str(j)) == 1:
                q = '0' + str(j)
            else:
                q = str(j)
                
            if a[0][0] == q[1] and a[0][1] == q[0]:
                k += 1
            if int(a[0][0]) + 1 == int(a[0][1]) and int(a[0][0]) + 1 == int(q[0]) and int(q[0]) + 1 == int(q[1]):
                k += 1
            if a[0] == q:
                k += 1
            if int(a[0][0]) == int(a[0][1]) and int(a[0][0]) == int(q[0]) and int(q[0]) == int(q[1]):
                k -= 1
                
    if (i + 1) != 24:
        i += 1
    else:
        i = 0

if i == b[2]:
    if len(str(i)) == 1:
        a[0] = '0' + str(i)
    else:
        a[0] = str(i)
    
    for j in range(b[1], b[3]+1):
        if len(str(j)) == 1:
            q = '0' + str(j)
        else:
            q = str(j)
                
        if a[0][0] == q[1] and a[0][1] == q[0]:
            k += 1
        if int(a[0][0]) + 1 == int(a[0][1]) and int(a[0][0]) + 1 == int(q[0]) and int(q[0]) + 1 == int(q[1]):
            k += 1
        if a[0] == q:
            k += 1
        if int(a[0][0]) == int(a[0][1]) and int(a[0][0]) == int(q[0]) and int(q[0]) == int(q[1]):
            k -= 1

print(k)