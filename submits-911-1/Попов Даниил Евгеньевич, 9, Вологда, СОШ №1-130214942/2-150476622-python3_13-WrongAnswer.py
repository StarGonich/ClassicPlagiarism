n = int(input())
l = list()

for i in range(n):
    l.append(i+1)
    
m = 1
for i in l:
    m = m * i
s = sum(l)
ans = str()

for i in range(n):
    ans = ans + str(l[i]) + " "
if m == s:
    print(m)
    print(ans)
else:
    print(-1)
