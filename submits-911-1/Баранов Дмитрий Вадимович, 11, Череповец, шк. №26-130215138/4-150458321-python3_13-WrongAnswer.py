n = int(input())
k = int(input())
p = []

for i in range(n + 1, n + k + 1):
    p.append(i)

if len(p) % 2 == 0:
    s = len(p) // 2
else:
    s = len(p) // 2 + 1
    
print(p[s])