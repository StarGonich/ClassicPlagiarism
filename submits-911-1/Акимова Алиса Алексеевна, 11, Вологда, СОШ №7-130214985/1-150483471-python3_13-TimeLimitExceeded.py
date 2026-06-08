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
h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
count = 0
ch = h1
cm = m1
while True:
    if is_beautiful(ch,cm):
        count += 1
    if ch == h2 and cm == m2:
        break
    cm += 1
    if cm == 60:
        cm = 0
        ch += 1
print(count)