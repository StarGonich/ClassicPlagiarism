n = int(input())
s = []
p = int(input())

for i in range(n):
    a = []

    t1, t2 = map(int, input().split())
    a.append(t1)
    a.append(t2)
    s.append(a)
for i in range(n - 1):
    if (s[i][1] - s[i][0]) >= p:
        c = s[i][1] - s[i][0]
        break
    
    if -s[i][1] + s[i + 1][1] < 3600:

        c = s[i + 1][0] + p - ((s[i][1] - s[i][0])) + 1 - 3600
        break
else:
    c = -1

print(c)

