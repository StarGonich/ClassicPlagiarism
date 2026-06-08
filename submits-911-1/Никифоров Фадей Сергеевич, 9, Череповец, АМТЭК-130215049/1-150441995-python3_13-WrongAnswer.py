h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
s = ''
k = 0
for i in range(h1, h2 + 1):
    for j in range(0, 60):
        a = ''
        b = ''


        

            
        
        if len(str(i)) == 1:
            a = a + '0' + str(i)
        else:
            a = a + str(i)
        if len(str(j)) == 1:
            b = b + '0' + str(j)
        else:
            b = b + str(j)
        
        c = b[1] + b[0]
        if ((a == b) or (a == c) or (a + b == '0123') or (a + b == '1234') or (a + b == '2345')) and not(h1 == i and j < m1):
            k += 1

        if i == h2 and j == m2:
            break

print(k)



