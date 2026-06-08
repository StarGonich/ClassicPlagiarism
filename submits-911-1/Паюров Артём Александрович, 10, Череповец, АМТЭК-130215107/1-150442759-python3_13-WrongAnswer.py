a = []
b = []
for i in range(4):
    a.append(int(input()))
    b.append(a[i])

'''h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())'''

k = 0

'''for i in range(len(a)):
    if len(str(a[i])) == 1:
        a[i] = '0' + str(a[i])
    else:
        a[i] = str(a[i])'''

i = b[0]

if i == b[2]:
    if len(str(i)) == 1:
        a[0] = '0' + str(i)
    else:
        a[0] = str(i)
    
    for j in range(b[1], b[3]):
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

i = b[0]

while i != b[2]:
    
    if len(str(i)) == 1:
        a[0] = '0' + str(i)
    else:
        a[0] = str(i)
                   
    if i == b[0]:
        for j in range(b[1], 61):
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
    
    if i > b[0] and i < b[2]:
        for j in range(0,61):
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
                
    if i == b[2]:
        for j in range(0,b[3]):
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
                
    if i != 24:
        i += 1
    else:
        i = 0
        
print(k)