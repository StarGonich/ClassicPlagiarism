h1 = int(input().strip())
m1 = int(input().strip())
h2 = int(input().strip())
m2 = int(input().strip())

def is_beautiful(h, m):
    hs = f"{h:02d}"
    ms = f"{m:02d}"
    if hs == ms:
        return True
    if ms == hs[::-1]:
        return True
    s = hs + ms
    for i in range(3):
        if int(s[i+1]) != int(s[i]) + 1:
            return False
    return True

count = 0
h, m = h1, m1
while True:
    if is_beautiful(h, m):
        count += 1
    if h == h2 and m == m2:
        break
    m += 1
    if m == 60:
        m = 0
        h = (h + 1) % 24

print(count)
