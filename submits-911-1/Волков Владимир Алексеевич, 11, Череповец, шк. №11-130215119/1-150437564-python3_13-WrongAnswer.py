h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
count = 0
h1 = h1 * 60
h2 = h2 * 60
hm1 = h1 + m1
hm2 = h2 + m2

for h in range(hm1, hm2 + 1):
    hs = str(h)
    if hs[0:2] == hs[2:4] or (hs[0] == hs[3] and hs[1] == hs[2]):
        count += 1
            
print(count)