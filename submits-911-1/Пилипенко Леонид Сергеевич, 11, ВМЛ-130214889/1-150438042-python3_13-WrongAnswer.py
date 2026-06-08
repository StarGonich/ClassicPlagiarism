h1, m1, h2, m2 = int(input()), int(input()), int(input()), int(input())
def nextT(h, m):
    m += 1
    if m==60:
        h+=1
        m = 0
    if h == 24:
        h = 0

    return (h, m)

def beauty(h, m):
    h, m = str(h), str(m)
    if len(h) == 1:
        h = '0'+h
    if len(m) == 1:
        m = '0'+m
    
    if h == m:
        return True
    if h == m[::-1]:
        return True
    if ord(m[1])-ord(m[0]) == 1 and ord(m[0])-ord(h[1]) == 1 and ord(h[1])-ord(h[0]) == 1:
        return True
    return False

h, m = h1, m1
h3, m3 = nextT(h2, m2)
ans = 0
while (h, m) != (h3, m3):
    if beauty(h, m):
        ans += 1
    h, m = nextT(h, m)
print(ans)
